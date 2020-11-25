//
// Created by patryk on 25.11.2020.
//

#ifndef CARDS_INDIVIDUAL_H
#define CARDS_INDIVIDUAL_H

#include <iostream>
#include <tuple>
#include <random>
#define N 10
#define S 100


class Individual {
    bool chromosome[N];
    int fitness;
    double influence;


public:

    Individual() {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist (0, 1);
        for(bool & i : chromosome) {
            i = dist(mt);
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

    int getFitness(int a ,int b){
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


    std::tuple<Individual, Individual> crossover(Individual parent) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist (0, N);
        int point = dist(mt);

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


};

#endif //CARDS_INDIVIDUAL_H
