#include <iostream>
#include "individual.h"
int main() {
    Individual parent1 = Individual();
    Individual parent2 = Individual();
    parent1.print();
    parent2.print();
    auto [a, b] = parent1.crossover(parent2);

    a.print();
    b.print();
    std::cout << "Fitness: " << a.getFitness(10,20)<< std::endl;
    return 0;
}
