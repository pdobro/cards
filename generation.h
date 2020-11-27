//
// Created by patryk on 25.11.2020.
//

#ifndef CARDS_GENERATION_H
#define CARDS_GENERATION_H

#define MU 15
#define LAMBDA 20

#define A 900
#define B 375

#define CROSSOVER_PROBABILITY 0.8
#define MUTATION_PROBABILITY 0.04


#include <vector>
#include <algorithm>
#include "individual.h"
#include "random.h"

class Generation {

    int population_size;
    int iterations;
    std::vector<Individual> population;

public:

    Generation() {
        population_size = S;
        iterations = 0;
        for(int i = 0; i < S; i++) {
            Individual individual;
            population.push_back(individual);
        }
        selection();
    }

    int calculateFitness(int a , int b) {
        for(auto &individual: population) {
            individual.setFitness(a, b);
        }
    }

    void calculateInfluence() {
        calculateFitness(A, B);
        int sum  = 0;
        int max = 0;
        for(auto &individual: population) {
                sum+= individual.getFitness();
                if (individual.getFitness() > max)
                    max = individual.getFitness();
        }

        for (auto &individual: population) {
            double influence = (double )(max - individual.getFitness() + 1)/(population_size * (max + 1) - sum);
                    individual.setInfluence(influence);
        }

    }

    std::vector<Individual> selection() {//rank selection
        std::vector<Individual> nextPopulation;
        calculateInfluence();
        std::sort(population.begin(), population.end());

        int i = 0;
        while(i < LAMBDA) {
            double pick = getRealRand(0, 1);
            for(auto &individual: population) {
                pick -= individual.getInfluence();

                if (pick < 0) {
                    nextPopulation.push_back(individual);
                    i++;
                    break;
                }
            }

        }
        return nextPopulation;
    }

    void strategyMuLambda() {
        std::vector<Individual> parents = selection();
        std::vector<Individual> children;

        for (int i = 0; i < population_size; i+=2) {
            Individual parentA = parents[i];
            Individual parentB = parents[i + 1];
            Individual childA;
            Individual childB;
            std::tuple<Individual, Individual> childrenPair;
            double crossover = getRealRand(0 ,1);
            if (crossover < CROSSOVER_PROBABILITY) {
                childrenPair = parentA.onePointCrossover(parentB);
                childA = std::get<0>(childrenPair);
                childB = std::get<1>(childrenPair);
            }
            else {
                childA = parentA;
                childB = parentB;
            }

            double mutation = getRealRand(0, 1);
            if (mutation < MUTATION_PROBABILITY)
                childA.mutate();

            mutation = getRealRand(0, 1);
            if (mutation < MUTATION_PROBABILITY)
                childB.mutate();

            childA.setFitness(A, B);
            childB.setFitness(A, B);

            children.push_back(childA);
            children.push_back(childB);
        }

        for (auto &child: children) {
            population.push_back(child);
        }

        std::sort(population.begin(), population.end());
        population.resize(MU);
        std::cout<<"fitness:  "<<population[0].getFitness()<<"\n";

    }

    int getFirst() {
        population[0].print();
        std::cout<<"\nfitness: "<<population[0].getFitness();
    }




};


#endif //CARDS_GENERATION_H
