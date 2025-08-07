
mkdir ./target

gcc -o analisador ./src/*.c

./target/analisador

read -n 1 -s -r -p ""

rm -rf ./target