//
// Created by patryk on 25.11.2020.
//

#ifndef CARDS_INDIVIDUAL_H
#define CARDS_INDIVIDUAL_H

#include <iostream>
#include <tuple>
#include <random>

#include "random.h"


#define N 50
#define S 20


class Individual {
    bool chromosome[N];
    int fitness;
    double influence;


public:

    Individual() {
        for(bool & i : chromosome) {
            i = getIntRand(0 , 1);
        }

    }

    void print(){
        int sumA = 0;
        int sumB = 0;
        for(int i = 0; i < N; i++) {

            if(chromosome[i]){
                std::cout<<"B ";
                sumB+= i + 1;}
            else {
                std::cout <<"A ";
                sumA += i + 1;
            }
        }
        std::cout<<"\n"<<"A: "<<sumA<<" B: "<<sumB<<"\n";
    }

    int setFitness(int a , int b){
        int heapA = 0;
        int heapB = 0;
        for(int i = 0; i < N; i++) {
            if(chromosome[i])
                heapB+= i + 1;
            else
                heapA+=i + 1;
        }
        fitness = abs(a - heapA) + abs(b - heapB);
        return fitness;
    }

    void mutate() {
        int bit = getIntRand(0, N - 1);
        chromosome[bit] = !chromosome[bit];
    }


    std::tuple<Individual, Individual> onePointCrossover(Individual parent) {
        int point = getIntRand(0, N - 1);

        Individual childA, childB;
        for(int i = 0; i < N; i++) {
            if (i < point) {
                childA.chromosome[i] = this->chromosome[i];
                childB.chromosome[i] = parent.chromosome[i];
            } else {
                childA.chromosome[i] = parent.chromosome[i];
                childB.chromosome[i] = this->chromosome[i];
            }
        }
        return {childA, childB};
    }

    bool operator <(const Individual &other) const {
        return fitness < other.fitness;
    }

    bool operator >(const Individual &other) const {
        return fitness > other.fitness;
    }

    int getFitness() const {
        return this->fitness;
    }

    double getInfluence() const {
        return this->influence;
    }

    void setInfluence(double val) {
        this->influence = val;
    }




};

#endif //CARDS_INDIVIDUAL_H
