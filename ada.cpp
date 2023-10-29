#include "ada.h"

double generateRandomAda(double lower_bound, double upper_bound) {
    static std::random_device rd;  // Random number seed
    static std::mt19937 generator(rd());  // Mersenne Twister random number generator
    std::uniform_real_distribution<double> distribution(lower_bound, upper_bound);
    return distribution(generator);
}

// Constructor
Ada::Ada(double base_price) : Stock(s_typeId, base_price) {}

// Override the PriceGenerator method
void Ada::PriceGenerator() {
    // Custom price generation logic for Ada
    // For demonstration, let's set the updated price to be 1.05 times the base price
    double randomFactor = generateRandomAda(0.9, 3.4);
    setUpdatedPrice(getBasePrice() * randomFactor);
}

// Override the typeId method
int Ada::typeId() const {
    return s_typeId;
}
