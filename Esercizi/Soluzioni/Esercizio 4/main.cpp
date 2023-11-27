#include <iostream>
#include <set>
#include <list>

#include "ribalta.h"

int main() {

    // std::set<int> s = {4, 2, 7, 9};
    // std::swap(*s.begin(), *(--s.end()));

    std::vector<int> v = {4, 2, 7, 9};
    Ribalta(v);

    for (const auto& e : v) {
        std::cout << e << ", ";
    }

    return EXIT_SUCCESS;
}