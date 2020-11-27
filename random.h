//
// Created by patryk on 27.11.2020.
//

#ifndef CARDS_RANDOM_H
#define CARDS_RANDOM_H

#include <random>

double getRealRand(int beg, int end) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist (beg, end);

    return dist(mt);
}

int getIntRand(int beg, int end) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist (beg, end);

    return dist(mt);
}

#endif //CARDS_RANDOM_H
