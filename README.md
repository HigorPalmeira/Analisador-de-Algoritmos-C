# Analisador de Algoritmos

## Visão Geral

O Analisador de Algoritmos (AnaBad) foi desenvolvido, na linguagem C, como projeto final para a disciplina de **Análise e Projeto de Algoritmos**.

O programa faz uma análise de tempo médio da execução de um algoritmo, que está incluído nos arquivos, e faz a medição da complexidade de tempo estimada de um arquivo com algoritmo, baseado na linguagem C.

## Como Compilar e Executar?

O AnaBad possui dois métodos principais de compilação/execução, com o compilador `gcc` e com o arquivo `runner.sh`.

* **GCC**:

Utilizando o `gcc` para compilar manualmente o projeto:

```bash
gcc -o anabad ./src/*.c ./algoritmos/*/*.c
```

> Certifique-se de que possui o compilador instalado em sua máquina.

* **Runner.sh**

Utilizando o arquivo `runner.sh` para compilar, automáticamente, e executar o analisador:

```bash
./runner.sh <parâmetros>
```

> Certifique-se de que possui o bash no seu terminal. 

**Obs.:** O arquivo `runner.sh` foi escrito por mim. Ele vai criar uma pasta temporária, onde o executável vai ficar, e executar o programa com os parâmetros passados.

## Parâmetros

Ao executar o programa, ele solicita alguns parâmetros por padrão. Se o programa for executado sem nenhum parâmetro passado, ele vai mostrar a mensagem padrão de ajuda.

| Parâmetro | Descrição |
| :---: | :--- |
| -a | análise de arquivo, complexidade de tempo estimada |
| -c | análise do tempo médio de execução de algoritmo |
| -h | exibe o guia de ajuda |

### Parâmetro -a

O programa espera que seja passado um arquivo após o parâmetro `-a`, o qual será **lido** e **analisado**.

*Exemplo de uso*
```bash
./anabad -a ./algoritmos/ordenacao/bubble_sort.c
ou
./runner.sh -a ./algoritmos/ordenacao/bubble_sort.c
```

### Parâmetro -c

O programa será executado, exibindo um menu com os algoritmos internos para testes. O primeiro menu mostrará o tipo de algoritmo, e o(s) outro(s) menu(s) exibirá(ão) os algoritmos em si para serem testados. Os resultados serão salvos na pasta `./resultados/tempo/` com o nome do algoritmo e a extensão `.csv`.

*Exemplo de uso*
```bash
./anabad -c
ou
./runner.sh -c
```

*Modelo de Saída do Arquivo de Resultados*
```csv
N,TempoMedio_ms
1000,6.922430
2000,25.863210
3000,49.125450
4000,76.962030
5000,108.835830
6000,163.978360
7000,207.301690
8000,275.619590
9000,357.359560
10000,436.268730
```

## Parâmetro -h

O programa irá exibir o seu menu de ajuda para o programa.

## Como incluir algoritmos?

Para incluir novos algoritmos para medir o tempo de execução, são necessários alguns passos simples.

1. Crie uma pasta, se necessário, em `./algoritmos` para o tipo de algoritmo a ser incluído.

2. Crie um arquivo (.c) com o nome do algoritmo, não utilize espaços.

3. Crie um arquivo header, na pasta `./includes`, com o nome do tipo de algoritmo (se ele existir, apenas adicione o novo algoritmo).

4. Inclua o algoritmo no arquivo `main.c`, na pasta `./src`. *Obs.:* Se preferir (recomendado) crie uma seção para o algoritmo na função do `menu()`.

* **OBS.:** Preste atenção no algoritmo a ser inserido. O programa faz as medições de tempo em funções com retorno `void` e dois parâmetros `int[], int` (vetor de valores e tamanho do vetor, respectivamente). Se necessário, crie funções utilitárias no arquivo do próprio algoritmo, para adequá-lo a formatação.
