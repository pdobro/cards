#include <iostream>

#include "generation.h"
int main() {
    Generation generation;

    for (int i = 0; i < 20; i++){
        generation.strategyMuLambda();
    }
    generation.getFirst();

    return 0;
}
