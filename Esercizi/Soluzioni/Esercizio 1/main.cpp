#include <iostream>

#include "mv.h"

int main(){

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Mean: " << Mean(v) << std::endl;
    std::cout << "Var: " << Variance(v) << std::endl;
    return EXIT_SUCCESS;
}