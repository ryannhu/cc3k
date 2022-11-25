#include "rando.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
int Rando::random_int(int low, int high) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::vector<int> gen;
    std::default_random_engine rng{seed};
    for (int i = low; i < high; ++i) { gen.emplace_back(i); }
    std::shuffle(gen.begin(), gen.end(), rng);

    return gen[0];

}

// int Random::randomNum(int top) {
//     vector<int> v;
//     for (int i = 0; i < top; i++) { v.push_back(i); }
//     unsigned seed = chrono::system_clock::now().time_since_epoch().count();
//     default_random_engine rng{seed};
//     std::shuffle( v.begin(), v.end(), rng );
//     return v[0];
// }