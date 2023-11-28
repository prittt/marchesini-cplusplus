#include <iostream>
#include "translate.h"

int main() {

    std::string s = "ciao";
    std::cout << s << " diventa ";
    Translate(s, "abdc", "wxzy");
    std::cout << s << std::endl;

    return EXIT_SUCCESS;
}