# Analisador de Algoritmos C

O Analisador faz a contagem do tempo médio (ms) da execução dos algoritmos.

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
