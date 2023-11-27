#ifndef MV_H_
#define MV_H_

#include <vector>

template <typename T>
double Mean(const std::vector<T> &v) {
    double sum = 0;
    for (const auto &num : v) {
        sum += static_cast<double>(num);
    }
    return sum / v.size();
}

template <typename T>
double Variance(const std::vector<T> &v) {
    double mean = Mean<T>(v);
    double sum = 0;
    for (const auto &num : v) {
        sum += (static_cast<double>(num) - mean) * (static_cast<double>(num) - mean);
    }
    return sum / v.size();
}

#endif