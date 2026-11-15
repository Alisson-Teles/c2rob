# C2ROB: tradução direta de `print` e `printf`

As chamadas diretas a `print` e `printf` são copiadas do C para o ROB
com o nome e os argumentos originais. As declarações em `compat/`
usam `...` para um Robcmp futuro. Veja [a tradução direta](docs/PRINTF.md)
para gerar e conferir o `.rob` sem compilá-lo.

Continuam disponíveis o [piloto de pré-processamento e noinline](docs/PILOTO_PREPROCESSAMENTO_NOINLINE.md)
e suas [evidências](docs/validacao-piloto/).

## Compilar e testar

Extraia em uma pasta separada e abra o terminal na pasta `c2rob/` do pacote.
Use GNU Make, Bison, Flex, um compilador C++20 com a biblioteca padrão
necessária (validado com G++ 14.2), um driver C `cc` compatível com as opções
do GCC e Python 3 para os testes. O piloto usa interfaces POSIX disponíveis
no Linux.

```bash
make
make test
```

Resultado validado: **259 passaram, 0 falharam**. O teste de integração
compila os casos aplicáveis e deixa os casos variádicos na etapa de
tradução. Use o `robcmp` já instalado e o `opt` da sua instalação LLVM.
Exemplo com LLVM 21:

```bash
make test-integration \
  ROBCMP="$(command -v robcmp)" \
  LLVM_OPT=opt-21 \
  ARCH=stm32f1 \
  OUT=out-integracao
```

## Experimentar no arquivo da amostra

```bash
./c2rob --preprocess test/cfiles/dummy.c
```

Para gerar os três arquivos de uma vez, com `robcmp` e
`llvm-objdump-21` no PATH:

```bash
make -C test OUT=out-piloto out-piloto/dummy.s
```

Os arquivos ficam em `test/out-piloto/`: `dummy.rob`, `dummy.o` e
`dummy.s`. O Makefile usa o piloto por padrão somente para `dummy.c`.
Ele aceita `ROBCMP`, `DUMP`, `ARCH`, `OUT` e `PREPROCESS_FILES`
na linha de comando. Use um `OUT` novo ao comparar configurações.

```bash
make -C test -k OUT=out-amostra
make -C test OUT=out-amostra count
```

Para traduzir o lote só até `.rob`, use outro diretório de saída:

```bash
make -C test -k OUT=out-direto translate
```
