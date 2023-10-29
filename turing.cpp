#include "turing.h"
#include <random>

double generateRandomTuring(double lower_bound, double upper_bound) {
    static std::random_device rd;  // Random number seed
    static std::mt19937 generator(rd());  // Mersenne Twister random number generator
    std::uniform_real_distribution<double> distribution(lower_bound, upper_bound);
    return distribution(generator);
}

// Constructor
Turing::Turing(double base_price) : Stock(s_typeId, base_price) {
//    m_priceUpdateTimer = new QTimer();
//    connect(m_priceUpdateTimer, &QTimer::timeout, this, &Turing::PriceGenerator);
//    m_priceUpdateTimer->start(3000);
}

// Override the PriceGenerator method
void Turing::PriceGenerator() {
    // Custom price generation logic for Turing
    double randomFactor = generateRandomTuring(0.3, 1.7);
    setUpdatedPrice(getBasePrice() * randomFactor);
}

// Override the typeId method
int Turing::typeId() const {
    return s_typeId;
}
