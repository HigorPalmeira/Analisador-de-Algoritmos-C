# Analisador de Algoritmos C

O Analisador faz a contagem do tempo médio (ms) da execução dos algoritmos.

## Visão Geral

O Analisador de Algoritmos foi elaborado na linguagem C e, faz a análise do tempo médio de execução de algoritmos e salva o resultado em um arquivo com extensão `.csv`, na pasta `resultados`. 

## Executar o Algoritmo

Pode executar utilizando o `Makefile`, na raiz do projeto execute o comando:
```bash
make
```

Utilizando o arquivo `runner.sh`, que está na raiz do projeto, execute o comando:
```bash
./runner.sh
```
> Certifique-se de utilizar um terminal que execute arquivos `.sh`.

Utilizando o compilador `gcc`:
```bash
gcc -o analisador ./src/*.c ./algoritmos/*.c
```
Ele vai criar um arquivo executável com o nome `analisador.exe`, agora execute o executável criado:
```bash
./analisador
```

## Algoritmos de Teste

Os algoritmos analisados, estão incluídos na pasta `./algoritmos`, e cada algoritmo incluído  possui um arquivo `header` na pasta `./includes`. É necessário incluir os headers no arquivo principal, e chamar a função `analisar`, passando seus parâmetros.

**Obs.:** Os algoritmos devem estar no formato `void algoritmo(int* vetor, int tamanho)`.
