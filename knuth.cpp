#include "knuth.h"
#include <random>

double generateRandomKnuth(double lower_bound, double upper_bound) {
    static std::random_device rd;  // Random number seed
    static std::mt19937 generator(rd());  // Mersenne Twister random number generator
    std::uniform_real_distribution<double> distribution(lower_bound, upper_bound);
    return distribution(generator);
}

// Constructor
Knuth::Knuth(double base_price) : Stock(s_typeId, base_price) {
}

// Override the PriceGenerator method
void Knuth::PriceGenerator() {
    // Custom price generation logic for Knuth
    // For demonstration, let's generate a random price between 0.8 to 1.2 times the base price
    double randomFactor = generateRandomKnuth(0.8, 1.2);
    setUpdatedPrice(getBasePrice() * randomFactor);
}

// Override the typeId method
int Knuth::typeId() const {
    return s_typeId;
}
