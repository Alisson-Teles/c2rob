# Suporte a `while` C no C2rob — documentação técnica

## Resultado e escopo

O C2rob agora reconhece `while` na entrada C e emite o laço de pré-teste já existente em ROB. Foram implementadas as quatro formas solicitadas: bloco com instruções, instrução única, corpo `;` e bloco `{}`. São aceitos aninhamentos e combinações com `for` e `if/else` dentro do subconjunto validado.

Todas as alterações pertencem ao C2rob, seus testes e sua documentação. **Nenhum arquivo do Robcmp foi alterado.** A comparação SHA-256 dos 814 arquivos extraídos de `robcmp.zip`, incluindo o build fornecido, confirmou identidade antes e depois. O novo build de validação ficou fora da árvore do Robcmp. Os 108 arquivos preexistentes do C2rob que não foram destinados à alteração permaneceram idênticos ao ZIP original; os testes anteriores foram preservados. Não havia `AGENTS.md` nos projetos fornecidos.

Não foram implementados `do/while`, `switch`, `goto`, `break` ou `continue`. Construções cuja semântica não pode ser preservada pelo emissor atual recebem diagnóstico e falha, em vez de serem removidas da saída.

## Confirmação inicial e TDD

A inspeção dos arquivos originais confirmou:

- `c2rob.l` reconhecia `for`, mas não tinha regra para `while`.
- `c2rob.y` não tinha token nem produção para `while`. As duas produções de `forstmt` emitiam inicialização, uma instância de `While` e a atualização ao final do corpo.
- A classe `While`, em `nodes.h`, já emitia `while condição { corpo }`.
- O Robcmp tinha `TOK_WHILE` em `src/Language.l`, produções `whileblock` em `src/Language.y`, geração de pré-teste em `src/While.cpp` e curto-circuito em `src/BinaryOp.cpp`.
- O diretório de referência presente no ZIP era **`robcmp/test/general`**, no singular. Ele utiliza arquivos independentes, Makefile, execução limitada por timeout e indicação de aprovação/falha.

Antes de modificar o tradutor, foram criados 37 testes em `test/unit`. O tradutor original foi recompilado com G++ usando os arquivos gerados fornecidos. A primeira execução registrou 2 aprovações e 35 falhas: o `for` de controle foi aceito, o `while` com bloco foi rejeitado e os novos diagnósticos ainda não existiam. `docs/validation/tdd-before.json` preserva esse registro. Os 20 casos adicionais foram acrescentados durante a revisão e a validação.

Havia uma exceção enganosa: `while (n < 0);` retornava sucesso, mas era interpretado como uma chamada à função chamada `while`, emitindo `while(n < 0);`. O teste passou a exigir a forma de laço ROB com bloco. Esse comportamento está preservado como evidência em `docs/validation/empty-semicolon-before.rob`.

Foram registrados três arquivos de referência para regressão: `for_regression.expected.rob`, `for_single_regression.expected.rob` e `for_logical_regression.expected.rob`. A saída final desses três casos permanece byte a byte igual à obtida do tradutor original.

## Arquivos e finalidade das alterações

| Arquivo ou grupo | Alteração e finalidade |
| --- | --- |
| `c2rob.l` | Reconhece `while`; identifica palavras-chave fora do escopo; distingue tokens de literais inteiros; transforma símbolos desconhecidos em erro efetivo; retorna falha estável quando há erro. |
| `c2rob.y` | Declara tokens; integra `whilestmt` em `local`; cria `whilebody` e `optional_locals`; chama a validação antes da emissão; preserva metadados de ponteiros e qualificadores; ajusta precedência e bitfields ao token inteiro; corrige a impressão de `int64_t` no trace. |
| `nodes.h` | Reutiliza `While`, acrescentando indicação de origem C e condição validada; protege o corpo nulo; fornece acesso ao AST e aos tipos; introduz `IntegerToken`; armazena metadados de ponteiro/qualificadores e a emissão validada das expressões. |
| `while_support.h` | Novo passe semântico limitado ao `while`: tipos e escopos, classificação de expressões, normalização booleana, agrupamento, validação de chamadas e diagnósticos conservadores. |
| `Makefile` | Build incremental com dependências explícitas de lexer, parser e cabeçalhos; variáveis de ferramentas; alvos `test` e `test-integration`; limpeza dos arquivos gerados. |
| `test/unit/Makefile` | Separa tradução de integração ROB/LLVM/execução; permite configurar executáveis e diretório de resultados. |
| `test/unit/run_tests.py` | Executa cada fixture; verifica sucesso/diagnóstico/saída; compara referências de `for`; compila ARM e nativo; verifica IR; compara resultados com C; registra cada etapa separadamente. |
| `test/unit/compare_sample.py` | Compara todos os mesmos arquivos C antes/depois; registra hashes, retornos, logs e tamanhos; separa C→ROB, ROB→objeto e verificação de IR. |
| `test/unit/cases.json`, 57 arquivos `.c` e três `.expected.rob` | Definem entradas, diagnósticos, fragmentos necessários, funções de entrada, argumentos de execução e referências de regressão. |
| `test/unit/.gitignore` | Ignora resultados temporários `out/`, `out-*/` e cache Python. |
| `docs/while-suporte.md`, `docs/validation/`, `docs/examples/` | Documentação, resultados reproduzíveis, auditoria, comparação da amostra e exemplo efetivamente traduzido/compilado. |
| `c2rob.tab.c`, `c2rob.tab.h`, `lex.yy.c`, `c2rob` | Arquivos preexistentes regenerados/recompilados. As fontes de manutenção são `.l`, `.y` e os cabeçalhos; não se editam esses arquivos gerados manualmente. |

## Reconhecimento sintático e reutilização de `While`

A nova regra do lexer precede a regra genérica de identificadores. `while` passa a produzir `TOK_WHILE`. A gramática acrescenta:

```bison
whilestmt : TOK_WHILE '(' expr ')' whilebody {
    $$ = new While($expr, $whilebody, true);
}
```

`whilebody` aceita um bloco com `optional_locals`, um `local` existente ou `;`. A instrução única é envolvida em uma lista de comandos; ambas as formas vazias recebem uma lista válida sem comandos. Isso evita desreferenciar um corpo vazio e permite manter o padrão de indentação de `While`.

O terceiro argumento do construtor indica um `while` diretamente escrito em C. As produções de `forstmt` continuam usando o construtor com dois argumentos, conservando a inicialização fora do laço e a atualização ao final do corpo. O caminho de emissão antigo é mantido para os programas sem `while` nativo. Quando um `for` envolve um novo `while`, ou está dentro dele, sua condição pode receber a mesma validação semântica para preservar a combinação.

Permanecem os dois conflitos shift/reduce preexistentes da gramática, relacionados ao `else`; nenhum novo conflito foi acrescentado. O teste `dangling_else.c` verificou o comportamento do `else` associado ao `if` mais próximo.

## Tipos, escopos e condições

O passe identifica classes do AST por `dynamic_cast`, os operadores pelo campo `operation` e os tipos pelas declarações, argumentos, assinaturas e mapeamentos já disponíveis no C2rob. Ele mantém categorias explícitas: inteiro, booleano, ponto flutuante, ponteiro, agregado, void e desconhecido.

Os tokens numéricos agora criam `IntegerToken`. Nomes e strings não são tratados como números pela aparência ou pela quantidade de filhos. O reconhecimento lexical de literais continua sendo responsabilidade do Flex; não foi criado um parser baseado em expressões regulares.

O ambiente contém variáveis globais, argumentos e declarações locais na ordem dos comandos. Os argumentos e variáveis locais podem ocultar nomes globais. Corpos de laços e ramos de `if/else` recebem cópias do escopo, evitando vazar declarações de um bloco para outro. Vetores locais/globais conhecidos e campos inteiros de estruturas declaradas recebem informações de tipo próprias. Ponteiros da fonte são marcados mesmo quando o emissor antigo apagava ou convertia essa informação.

| Expressão C | Tratamento na condição ROB |
| --- | --- |
| `i < n` | Permanece comparação booleana. |
| `n` | `n != 0`. |
| `n - 1` | `(n - 1) != 0`. |
| `((n))` | Mantém os parênteses e compara o valor inteiro com zero. |
| `n && (n - 1)` | `(n != 0) and ((n - 1) != 0)`. |
| `!n` | `!(n != 0)`. |
| `proximo(n)` com assinatura inteira conhecida | `proximo(n) != 0`, com uma única chamada por avaliação da condição. |
| `n--`, inclusive em comparação ou argumento | Falha com diagnóstico de pós-incremento/decremento usado como valor. |

A decisão entre booleano e número no novo caminho nunca utiliza `getChildren().size()`. O emissor preexistente de condições fora desse caminho continua preservado; `checkedExpression` evita sua heurística antiga nos novos laços e nas condições que os controlam.

### Precedência, parênteses e curto-circuito

A precedência do parser C foi ajustada para que igualdade e comparação tenham prioridade sobre operadores bit a bit. Isso é necessário, por exemplo, para interpretar `n & 1 == 1` como `n & (1 == 1)`, conforme C. ROB utiliza outra ordem nesse ponto, por isso o agrupamento obtido do AST é explicitado na emissão. Parênteses escritos na fonte são preservados; outros são acrescentados quando necessários para conservar a árvore.

Os operandos inteiros de `&&` e `||` são normalizados individualmente, e os operadores são emitidos como `and` e `or`. A geração de curto-circuito permanece inteiramente no Robcmp existente. Comparações ou resultados lógicos usados em operações inteiras recebem conversão `int32(...)`, pois C produz um resultado inteiro e ROB produz um booleano.

O passe constrói texto a partir do AST; ele não executa as expressões e não cria inicializações antecipadas da condição. Chamadas continuam dentro da condição do laço, sem duplicação. O Robcmp existente gera o bloco de teste antes do corpo e retorna ao teste depois de cada iteração.

## Diagnósticos e limites semânticos

As falhas têm mensagem em `stderr`, código de retorno não zero e nenhuma saída ROB normal. O retorno foi normalizado para 0/1, evitando que uma quantidade de erros múltipla de 256 se transforme em sucesso no shell. `-f` não contorna a validação nem libera emissão de entradas inválidas; `-d` continua disponível para trace.

Recebem diagnóstico:

- `do`, `switch`, `goto`, `break`, `continue`, `case` e `default`, sem implementação dessas construções.
- Pós-incremento/decremento usado como valor em condições, argumentos, comparações ou expressões do corpo. `n--;` e `n++;` como instruções isoladas permanecem aceitos para variáveis inteiras.
- Condições e expressões verificadas com ponteiros, ponto flutuante, agregados, void ou tipo desconhecido. Chamadas nesse caminho exigem assinatura conhecida e parâmetros escalares inteiros/booleanos.
- Acessos `volatile`, pois a tradução preexistente descartava esse qualificador; variáveis locais `static` relevantes ao laço, cuja duração também não era preservada.
- Acesso a campo de elemento de vetor cuja emissão antiga utilizava uma leitura antecipada para `aux`.
- Inicialização de vetor de estruturas ou inicialização parcial de estrutura no corpo, cuja emissão antiga não preservava os valores/zeros necessários.
- Símbolos lexicais desconhecidos e demais sintaxes não aceitas pelo parser existente.

Essas restrições também se aplicam às expressões verificadas dentro do novo laço. Não se promete suporte geral à linguagem C: pré-processamento, assinaturas que o parser antigo não aceita, conversões/ABIs e construções independentes do `while` permanecem no escopo anterior. A validação de execução concentrou-se em inteiros compatíveis com os testes; ela não cobre todas as larguras de tipos ou casos de comportamento indefinido de C.

## Como compilar e executar

O build requer GNU Make 4.3 ou posterior, Flex, Bison, Python 3 e um compilador C++20 com `<format>`. Nesta sessão foram usados G++ 13.3, Make 4.3, Flex 2.6.4 e Bison 3.8.2. O compilador C e `objcopy` são necessários para comparar execução nativa.

Dentro da pasta `c2rob`:

```bash
make -B CXX=g++
make test
./c2rob test/unit/comparison.c > contar.rob
```

Também é possível usar `make -B CXX=clang++-21` quando esse compilador e a biblioteca C++ adequada estiverem disponíveis. `make test` executa tradução, referências e diagnósticos; registra a integração como não executada.

Para compilar o Robcmp original sem escrever em sua árvore, considerando os diretórios `c2rob` e `robcmp` como irmãos:

```bash
cmake -S ../robcmp -B ../robcmp-validation \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DLLVM_DIR="$(llvm-config-19 --cmakedir)"
cmake --build ../robcmp-validation -j2

make test-integration \
  ROBCMP="$(realpath ../robcmp-validation/robcmp)" \
  LLVM_OPT=opt-19
```

Os caminhos e a versão do LLVM podem ser configurados. `test/unit/run_tests.py --help` expõe também `--cc`, `--objcopy`, `--arch`, `--out` e `--filter`. Caso o Robcmp indicado não exista, a integração falha explicitamente. Ausência de `opt`, compilador C ou `objcopy` é registrada como etapa não executada, sem ser contada como IR verificado ou execução validada.

### Adaptador necessário ao Robcmp atual

O Robcmp fornecido falha ao gerar um módulo sem `main`: `Program::generate()` acessa o resultado de uma busca malsucedida por esse símbolo. O problema foi reproduzido com o `for` original e com o exemplo `contar`, e os logs estão em `docs/validation/mainless-probe.json`.

Cada fixture conserva sua tradução exata em `nome.rob`. Para integração, o runner cria **outro arquivo**, `nome.validation.rob`, acrescentando apenas:

```rob
int32 main() { return 0; }
```

Os objetos ARM e o IR verificado correspondem a essa cópia com adaptador. Para execução nativa, o `main` do objeto de teste é renomeado com `objcopy` para `rob_validation_main`; o driver C chama esse inicializador uma vez e executa as funções traduzidas. O driver do C original executa a mesma sequência de argumentos. O Robcmp e a saída original do tradutor permanecem intactos.

Para conferir manualmente o exemplo com adaptador:

```bash
../robcmp-validation/robcmp -O0 -a stm32f1 \
  -o contar.arm.o docs/examples/contar.validation.rob
../robcmp-validation/robcmp -O0 -a stm32f1 \
  docs/examples/contar.validation.rob > contar.ll
opt-19 -passes=verify -disable-output contar.ll
```

### Comparação da amostra

O diretório original deve conter o binário anterior e as fontes extraídas do ZIP. O comando seguinte utiliza a mesma amostra, sem pré-processamento nem correção de seus arquivos:

```bash
python3 test/unit/compare_sample.py \
  --before ../c2rob-original/c2rob \
  --after ./c2rob \
  --sample ../amostra_c2rob \
  --out test/unit/out-sample \
  --robcmp "$(realpath ../robcmp-validation/robcmp)" \
  --opt opt-19
```

Na comparação da amostra **não se acrescenta o adaptador `main`** nem bibliotecas: compilam-se diretamente as saídas obtidas. `comparison.csv` registra cada arquivo, hash da entrada, retornos e bytes. Os logs por etapa permanecem no diretório indicado por `--out`.

## Resultados executados

| Verificação | Resultado |
| --- | --- |
| Build do C2rob a partir de Flex/Bison | Concluído. |
| Tradução e diagnósticos | **57/57 testes aprovados**: 32 entradas aceitas e 25 rejeições esperadas. |
| Regressão textual de `for` | Três referências idênticas à versão original. |
| ROB→objeto STM32F1, com adaptador de entrada | **32/32 aprovados**, objetos ARM EABI5. |
| IR STM32F1 verificado por `opt -passes=verify` | **32/32 aprovados**, LLVM 19.1.1. |
| Execução nativa comparada com o C original | **32/32 fixtures equivalentes**, total de **102 chamadas** às funções de teste. |
| AddressSanitizer + UndefinedBehaviorSanitizer | **57/57 aprovados**; detecção de vazamentos desativada devido às alocações persistentes do AST preexistente. |
| Auditoria do Robcmp | 814 arquivos idênticos por SHA-256; nenhum arquivo acrescentado/removido/alterado na árvore original. |

O código objeto e o IR foram produzidos com `-O0`. A comparação de execução usou o backend nativo; não foi execução no STM32. Os testes vazios foram executados com condições falsas para evitar laços legitimamente infinitos.

| Fixture | Argumentos | Resultados C e ROB |
| --- | --- | --- |
| `comparison` / `contar` | -1, 0, 1, 5 | 0, 0, 1, 5 |
| `false_condition` | 0, 1, 5 | 7, 7, 7: o corpo não foi executado. |
| `short_circuit` | 0, 1, 5 | 0, 1, 5 chamadas ao operando direito de `&&`. |
| `short_circuit_or` | 0, 1, 5 | 10, 11, 15: uma chamada final ao operando direito de `||`, codificada junto ao número de iterações. |
| `call_once` | 0, 1, 5 | 10, 21, 65: exatamente n+1 avaliações da condição e n execuções do corpo. |
| `for_regression` | 0, 1, 5 | 0, 0, 10 |

A cobertura inclui também aritmética, parênteses, negação, precedência bit a bit, resultado booleano em operação inteira, unsigned, vetores inteiros, campos de estrutura, ocultação de nome global, declaração local, aninhamentos, combinações de laços e `if/else`.

### Amostra de 150 arquivos

| Etapa | Antes | Depois |
| --- | ---: | ---: |
| C→ROB com retorno zero e saída não vazia | 1/150 | 1/150 |
| ROB→objeto STM32F1 | 0/150 | 0/150 |
| IR verificado | 0/150 | 0/150 |
| Novas traduções aceitas | — | 0 |
| Traduções anteriormente aceitas que deixaram de ser aceitas | — | 0 |

O único retorno zero foi `embench-iot/support/board.c`, que emitiu somente `use boardsupport;`. O Robcmp não encontrou `boardsupport.rob`, portanto esse retorno de tradução não representa um programa compilável. Os outros 149 arquivos continuaram bloqueados por construções/dependências do conjunto original. **Não foi demonstrado aumento da taxa de conversão nessa amostra**, nem ganho de desempenho ou redução de objeto. A presença de `while` nos arquivos não foi utilizada como estimativa de sucesso.

### Impedimentos superados e validações pendentes

Flex, Bison, CMake e LLVM não estavam instalados inicialmente. A instalação global falhou por permissões do ambiente; os pacotes necessários foram obtidos e extraídos localmente para executar as ferramentas. Isso permitiu concluir os testes indicados acima.

O binário Robcmp incluído no ZIP depende de `libLLVM.so.21.1`, ausente no ambiente. Foi validado o **mesmo código-fonte fornecido**, sem alterações, recompilado com LLVM 19.1.1 em `RelWithDebInfo`. A execução específica do binário vinculado ao LLVM 21 permanece pendente. Também permanecem pendentes execução em placa STM32F1, ligação de firmware completo e uma nova avaliação do corpus com cabeçalhos/pré-processamento e outras construções independentes resolvidas. Essas etapas não são contadas como aprovadas.

## Exemplo real obtido

Entrada em `docs/examples/contar.c`:

```c
int contar(int n) {
    int i = 0;
    while (i < n) {
        i++;
    }
    return i;
}
```

Saída emitida em `docs/examples/contar.rob`:

```rob
int32 contar(int32 n) {
	i = int32(0);
	while i < n {
		i++;
	}

	return i;
}
```

`contar.validation.rob`, `contar.ll` e `contar.arm.o` fornecem a cópia com entrada de validação e seus resultados. A função `contar` devolveu os mesmos valores do C para -1, 0, 1 e 5.

## Evidências e aplicação da entrega

`docs/validation/` reúne a fase inicial TDD, resultados de tradução, integração e sanitizers, logs, ambiente, CSV da amostra, resumo e fingerprints do Robcmp. `test/unit/cases.json` é a lista completa e executável dos casos. Os diretórios `out*` podem ser recriados pelos comandos acima.

O pacote completo contém o C2rob atualizado com seus arquivos anteriores e a documentação. O patch incremental contém fontes, novos testes e documentação textual; os arquivos Flex/Bison e o binário são regenerados pelo build. Para aplicá-lo em uma cópia da base original:

```bash
git apply --check ../c2rob-while.patch
git apply ../c2rob-while.patch
make -B CXX=g++
make test
```

A checagem do patch deve ser feita antes de aplicá-lo em um projeto que tenha outras mudanças locais. Não foi criado commit, resetado histórico ou modificado conteúdo anterior dos testes. **A linguagem ROB, a gramática do Robcmp e sua geração de LLVM IR não receberam nenhuma alteração.**
