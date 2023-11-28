#include <iostream>

#include "farfallino.h"

int main() {
    std::string input = "ciao"; // {'c', 'i', 'a', 'o'};
    std::string codificata = CodificaFarfallino(input);
    std::cout << input << " in farfallino diventa " << codificata << std::endl;

    return EXIT_SUCCESS;
}