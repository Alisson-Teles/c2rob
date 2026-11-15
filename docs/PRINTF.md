# Tradução direta de print e printf

Esta implementação substitui a versão com vetor de argumentos. Uma
chamada no C como:

```c
printf("Pedido recebido\n");
printf("Itens: %d\n", quantidade * preco_unitario);
```

aparece desta forma no ROB:

```rob
use printf;

// Dentro da função:
printf("Pedido recebido\n");
printf("Itens: %d\n", quantidade * preco_unitario);
```

O tradutor copia do nome da função até o parêntese de fechamento.
Preserva expressões, escapes, comentários dentro da chamada, formatação
e ordem dos argumentos. A regra vale para chamadas por nome a `print`
e `printf`, inclusive chamadas aninhadas, usadas como comandos ou em
expressões. O restante do programa continua passando pelo tradutor normal.

Quando falta uma declaração no próprio programa, o tradutor importa
`compat/printf.rob` com `use printf;` ou `compat/print.rob` com
`use print;`. Cada cabeçalho declara seu próprio nome, por exemplo:

```rob
int32 printf(char[] format, ...);
```

Essas declarações especificam a interface para o futuro Robcmp.
A versão atual do Robcmp não compila os protótipos com `...`.
Uma declaração ou definição presente no C é traduzida e usada em vez
de uma importação extra. O protótipo C padrão de printf, como
`extern int printf(const char *restrict fmt, ...);`, também é aceito.
`print` não é uma função padrão da biblioteca C.

O conteúdo copiado da chamada não é convertido para o conjunto de
expressões do ROB atual. Por exemplo, sufixos como `7U`, formatos
guardados em variáveis e nomes dentro dos argumentos preservam sua
grafia C. A tradução direta não valida a correspondência entre o
formato e seus valores. Se usar `--preprocess`, a cópia reflete a
chamada após o pré-processamento, que tem as mesmas restrições do piloto.

## Como verificar

Da raiz do projeto:

```bash
make test
./c2rob test/unit/print_direct_pedido.c
./c2rob test/unit/print_direct_medicao.c
./c2rob test/unit/print_direct_chamadas.c
```

A tradução direta é o padrão; a opção antiga `--printf` é aceita como
sinônimo. Para salvar um único arquivo em `test/cfiles/` sem chamar
o Robcmp:

```bash
make -C test OUT=out-direto out-direto/printf_pedido.rob
```

O comando acima pressupõe que `test/cfiles/printf_pedido.c` já existe.
Também é possível executar `make -C test -k OUT=out-direto translate`
para traduzir o lote sem compilar os objetos.

Há 11 novos casos em `test/unit`: oito comparações de tradução sem
compilação, dois diagnósticos de delimitadores e uma função `print`
de assinatura fixa, que é compilada e executada. Os testes de
integração dos demais casos continuam disponíveis.
