CXX ?= g++
CXXFLAGS ?= -std=c++20 -g -O1
FLEX ?= flex
BISON ?= bison

.PHONY: all clean test test-integration
all: c2rob

c2rob.tab.c c2rob.tab.h &: c2rob.y nodes.h source_type.h scope_support.h while_support.h qualifier_support.h integer_support.h
	$(BISON) -d c2rob.y

lex.yy.c: c2rob.l c2rob.tab.h
	$(FLEX) c2rob.l

c2rob: c2rob.tab.c lex.yy.c nodes.h source_type.h scope_support.h while_support.h qualifier_support.h integer_support.h
	$(CXX) $(CXXFLAGS) c2rob.tab.c lex.yy.c -o $@

test: c2rob
	$(MAKE) -C test/unit test

test-integration: c2rob
	$(MAKE) -C test/unit integration

clean:
	rm -f c2rob.tab.c c2rob.tab.h lex.yy.c c2rob
	$(MAKE) -C test/unit clean
