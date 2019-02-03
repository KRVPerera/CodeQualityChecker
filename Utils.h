#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <numeric>
#include "Common.h"

long RequiredSampleSize(double sd, double mean) {
    long N = (long) ceil(((double) 100 * 1.960 * sd) / (5 * mean));
    return N;
}

double Mean(std::vector<double>& times) {
    auto size = times.size();
    double sum;
    sum = std::accumulate(times.begin(), times.end(), 0);
    return (double) sum / size;
}

double StandardDeviation(std::vector<double>& times) {
    double mean = Mean(times);
    double variance = 0;
    for (size_t i = 0; i < times.size(); ++i) {
        variance += pow(times.at(i) - mean, 2);
    }
    variance = variance / times.size();
    return sqrt(variance);
}

long RequiredSampleSize(std::vector<double>& times) {
    return RequiredSampleSize(StandardDeviation(times), Mean(times));
}

double Average(std::vector<double>& times) {
    if (times.empty()) return 0;
    double total = 0;
    size_t items = times.size();

    for (size_t i = 0; i < items ; ++i) {
        total += times[i];
    }

    return total/items;
}

#endif // UTILS_H
