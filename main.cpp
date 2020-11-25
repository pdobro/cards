#include <iostream>
#include "individual.h"
#include "generation.h"
int main() {
    Individual parent1;
    Individual parent2;
    std::vector<Individual> T;

    parent1.print();
    parent2.print();
    auto [a, b] = parent1.crossover(parent2);

    a.print();
    b.print();
    std::cout << "Fitness: " << a.getFitness(10,20)<< std::endl;

    return 0;
}
