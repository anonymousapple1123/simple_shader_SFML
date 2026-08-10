echo "=================COMPILING================="
BREW_PREFIX=$(brew --prefix)

clang++ -std=c++17 pattern.cpp -o app \
    -I"$BREW_PREFIX/include" \
    -L"$BREW_PREFIX/lib" \
    -lsfml-window -lsfml-system -lsfml-graphics

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running..."
    ./app
else
    echo "!!! Compilation failed !!!"
fi
