
TARGET="./target"
SRC="./src"
ALGORITMOS="./algoritmos"
EXECUTAVEL="anabad"

clear

if [ -d "$TARGET" ]; then
    rm -rf $TARGET/
fi

mkdir $TARGET

gcc -o $TARGET/$EXECUTAVEL $SRC/*.c $ALGORITMOS/*/*.c

$TARGET/$EXECUTAVEL $@

echo "Pressione qualquer tecla para continuar..."
read -n 1 -s -r -p ""
