# C2ROB: piloto de pré-processamento e `noinline`

Esta versão parte do C2ROB de **especificadores de tipos e qualificadores**.
Ela acrescenta um modo opcional de pré-processar fontes C independentes,
traduz o atributo de função GNU `noinline` e reúne os cabeçalhos do tradutor
em `include/`. O exemplo completo é `test/cfiles/dummy.c`, preservado como
veio na amostra.

O [guia de implementação](docs/PILOTO_PREPROCESSAMENTO_NOINLINE.md)
explica o código, os limites, cada teste novo e a comparação com a versão
anterior. O [inventário](docs/ARQUIVOS_COMPARADOS.txt) lista os arquivos
por categoria. As [evidências](docs/validacao-piloto/) incluem o ROB, LLVM IR,
desmontagem STM32F1 e a comparação de execução de `dummy.c`.

## Compilar e testar

Extraia em uma pasta separada e abra o terminal na pasta `c2rob/` do pacote.
Use GNU Make, Bison, Flex, um compilador C++20 com a biblioteca padrão
necessária (validado com G++ 13.3), um driver C `cc` compatível com as opções
do GCC e Python 3 para os testes. O piloto usa interfaces POSIX disponíveis
no Linux.

```bash
make
make test
```

Resultado validado: **248 passaram, 0 falharam**. Para a integração, use o
`robcmp` já instalado e o `opt` da sua instalação LLVM. Exemplo com LLVM 21:

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

Na amostra de 142 entradas, a rodada continua indicando as falhas dos
outros arquivos. O ganho verificado é **um arquivo inteiro a mais**:
`dummy.c` traduz, compila para ARM e tem desmontagem. O caso `board.c`
ainda informa a dependência ausente `boardsupport.rob`.
