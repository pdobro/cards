#include <iostream>
#include <chrono>

#include "generation.h"

#define MAX_ITERATIONS 50
int main() {
    Generation generation;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX_ITERATIONS; i++){
        if (generation.getFirst() > 8)
            generation.strategyMuLambda();
        else {
            std::cout<<i;
            break;
        }
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
    generation.getFirst();

    return 0;
}
