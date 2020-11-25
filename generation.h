//
// Created by patryk on 25.11.2020.
//

#ifndef CARDS_GENERATION_H
#define CARDS_GENERATION_H

#include <vector>
#include "individual.h"

class Generation {

    int population_size;
    int iterations;
    std::vector<Individual> population;

public:

    Generation() {
        population_size = S;
        for(int i = 0; i < S; i++) {
            Individual individual;
            population.push_back(individual);
        }
    }

    int getBestFitness(int a, int b) {
        int result = 55;
        for(auto &individual: population) {
            if (individual.getFitness(a, b) < result)
                result = individual.getFitness(a, b);
        }
    }

    void selection();
    void strategy();




};


#endif //CARDS_GENERATION_H
