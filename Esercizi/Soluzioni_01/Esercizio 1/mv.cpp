#include "mv.h"

double Mean(const std::vector<int> &v) {
    double sum = 0;
    for (int num : v) {
        sum += num;
    }
    return sum / v.size();
}

double Variance(const std::vector<int> &v) {
    double mean = Mean(v);
    double sum = 0;
    for (int num : v) {
        sum += (num - mean) * (num - mean);
    }
    return sum / v.size();
}