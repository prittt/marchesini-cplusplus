#ifndef MV_H_
#define MV_H_

template <typename Iterator>
double Mean(Iterator begin, Iterator end) {
    double sum = 0;
    size_t count = 0;
    for(auto it = begin; it != end; ++it){
        sum += static_cast<double>(*it);
        ++count;
    }
    
    return sum / count;
}

template <typename Iterator>
double Variance(Iterator begin, Iterator end) {
    double mean = Mean<Iterator>(begin, end);
    double sum = 0;
    size_t count = 0;

    for(auto it = begin; it != end; ++it){
        sum += (static_cast<double>(*it) - mean) * (static_cast<double>(*it) - mean);
        ++count;
    }
    
    return sum / count;
}

#endif