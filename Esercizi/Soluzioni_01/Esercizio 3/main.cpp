#include <iostream>
#include <vector>
#include <list>

#include "mv.h"

int main(){

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Mean: " << Mean(v.begin(), v.end()) << std::endl;
    std::cout << "Var: " << Variance(v.begin(), v.end()) << std::endl;

    
    std::vector<double> v1 = {1., 2., 3., 4., 5.};
    std::cout << "Mean: " << Mean(v1.begin(), v1.end()) << std::endl;
    std::cout << "Var: " << Variance(v1.begin(), v1.end()) << std::endl;
    
    std::list<double> l = {1., 2., 3., 4., 5.};
    std::cout << "Mean: " << Mean(l.begin(), l.end()) << std::endl;
    std::cout << "Var: " << Variance(l.begin(), l.end()) << std::endl;
    
    return EXIT_SUCCESS;
}