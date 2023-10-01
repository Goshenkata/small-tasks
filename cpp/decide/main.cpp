#include <iostream>
#include "Random.h"

int main(int argc, char* argv[]) {
    int randomIndex = Random::get(2, argc) - 1;
    std::cout << argv[randomIndex] << std::endl;
    return 0;
}
