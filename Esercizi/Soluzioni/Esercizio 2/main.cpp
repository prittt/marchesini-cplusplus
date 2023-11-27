#include <iostream>

#include "mv.h"

int main(){

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Mean: " << Mean<int>(v) << std::endl;
    std::cout << "Var: " << Variance<int>(v) << std::endl;

    
    std::vector<double> v1 = {1., 2., 3., 4., 5.};
    std::cout << "Mean: " << Mean<double>(v1) << std::endl;
    std::cout << "Var: " << Variance<double>(v1) << std::endl;
    return EXIT_SUCCESS;
}