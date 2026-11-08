#pragma once

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <spawn.h>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

extern char **environ;

namespace cpreprocess {

inline bool isIncludeDirective(std::string_view line) {
    const size_t hash = line.find_first_not_of(" \t");
    if (hash == std::string_view::npos || line[hash] != '#') return false;
    const size_t word = line.find_first_not_of(" \t", hash + 1);
    if (word == std::string_view::npos) return false;
    line.remove_prefix(word);
    return line.starts_with("include") || line.starts_with("import");
}

inline void checkStandaloneInput(FILE *expanded) {
    // -dI preserves active includes in the output, including macro operands.
    // Do not hand the expanded contents of such units to the translator.
    char *line = nullptr;
    size_t capacity = 0;
    ssize_t length;
    bool includes = false;
    while ((length = ::getline(&line, &capacity, expanded)) >= 0) {
        if (isIncludeDirective(std::string_view(line, length))) {
            includes = true;
            break;
        }
    }
    std::free(line);
    if (includes)
        throw std::runtime_error("active #include or #import is outside the standalone pilot");
    if (!std::feof(expanded) || std::ferror(expanded))
        throw std::runtime_error("could not inspect expanded C input");
}

inline FILE *open(const char *path) {
    auto close = [](FILE *file) { std::fclose(file); };
    std::unique_ptr<FILE, decltype(close)> expanded(std::tmpfile(), close);
    if (!expanded)
        throw std::system_error(errno, std::generic_category(), "could not create a temporary stream");

    const char *configured = std::getenv("C2ROB_CC");
    const std::string compiler = configured && *configured ? configured : "cc";
    std::string input(path);
    // GCC interprets an argv item starting with @ as a response file.
    if (input.starts_with('@')) input.insert(0, "./");
    std::vector<std::string> arguments{
        compiler, "-E", "-P", "-nostdinc", "-dI", "-x", "c", "-std=c11", input
    };
    std::vector<char*> argv;
    for (auto &argument : arguments) argv.push_back(argument.data());
    argv.push_back(nullptr);

    posix_spawn_file_actions_t actions;
    int error = posix_spawn_file_actions_init(&actions);
    if (error)
        throw std::system_error(error, std::generic_category(), "could not initialize compiler invocation");

    const int output = fileno(expanded.get());
    error = posix_spawn_file_actions_adddup2(&actions, output, STDOUT_FILENO);
    if (!error && output != STDOUT_FILENO)
        error = posix_spawn_file_actions_addclose(&actions, output);
    pid_t process;
    if (!error)
        error = posix_spawnp(&process, compiler.c_str(), &actions, nullptr, argv.data(), environ);
    posix_spawn_file_actions_destroy(&actions);
    if (error)
        throw std::system_error(error, std::generic_category(), "could not run " + compiler);

    int status;
    pid_t waited;
    do { waited = waitpid(process, &status, 0); } while (waited == -1 && errno == EINTR);
    if (waited == -1)
        throw std::system_error(errno, std::generic_category(), "could not wait for C compiler");
    if (WIFSIGNALED(status))
        throw std::runtime_error("C compiler stopped by signal " + std::to_string(WTERMSIG(status)));
    if (!WIFEXITED(status))
        throw std::runtime_error("C compiler did not exit normally");
    if (WEXITSTATUS(status) != 0)
        throw std::runtime_error("C compiler exited with status " + std::to_string(WEXITSTATUS(status)));

    if (std::fseek(expanded.get(), 0, SEEK_SET) != 0)
        throw std::system_error(errno, std::generic_category(), "could not seek to expanded C input");
    checkStandaloneInput(expanded.get());
    if (std::fseek(expanded.get(), 0, SEEK_SET) != 0)
        throw std::system_error(errno, std::generic_category(), "could not rewind expanded C input");
    return expanded.release();
}

} // namespace cpreprocess
