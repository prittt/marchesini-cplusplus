#include <iostream>
#include "conta.h"

int main() {

    std::string str = "  Questa e' una stringa lunga 45 caratteri.";
    std::cout << Conta(str) << std::endl;

    return EXIT_SUCCESS;
}