#ifndef ADA_H
#define ADA_H
#include <random>
#include "stock.h"

class Ada : public Stock {
public:
    Ada(double base_price);

    // Override the virtual functions from the Stock class
    void PriceGenerator() override;
    int typeId() const override;

private:
    static const int s_typeId = 1;
};

#endif // ADA_H


