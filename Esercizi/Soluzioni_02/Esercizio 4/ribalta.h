#ifndef RIBALTA_H_
#define RIBALTA_H_

#include <vector>
#include <algorithm>

template <typename T>
void Ribalta(std::vector<T> &v) {
    // auto start = v.begin();
    // auto end = v.end();

    // while (start != end) {
    //     --end;
    //     if (start == end) {
    //         break;
    //     }
    //     std::swap(*start, *end);
    //     ++start;
    // }
    //std::reverse(v.begin(), v.end());
    std::reverse(begin(v), end(v));
}

#endif