#include "random"

#ifndef HI_LO_RANDOM_H
#define HI_LO_RANDOM_H
namespace Random {
    inline std::mt19937 generate() {
        std::random_device rd{};
        std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
        return std::mt19937 {ss};
    }

    inline std::mt19937 mt{generate()};

    inline int get(int min, int max) {
        return std::uniform_int_distribution{min, max}(mt);
    }
}

#endif //HI_LO_RANDOM_H
