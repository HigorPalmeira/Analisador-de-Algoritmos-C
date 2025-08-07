
mkdir ./target

gcc -o ./target/analisador ./src/*.c ./algoritmos/*.c

./target/analisador

echo "Pressione qualquer tecla para continuar..."
read -n 1 -s -r -p ""

rm -rf ./target