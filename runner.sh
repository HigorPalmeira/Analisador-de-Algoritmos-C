
clear

if [ -d "./target" ]; then
    rm -rf ./target
fi

mkdir ./target

gcc -o ./target/analisador ./src/*.c ./algoritmos/*/*.c

./target/analisador $@

echo "Pressione qualquer tecla para continuar..."
read -n 1 -s -r -p ""
