#ifndef KNUTH_H
#define KNUTH_H
#include "stock.h"

class Knuth : public Stock {
public:
    Knuth(double base_price);

    // Override the virtual functions from the Stock class
    void PriceGenerator() override;
    int typeId() const override;

private:
    static const int s_typeId = 2;
//    QTimer* m_priceUpdateTimer;
};

#endif // KNUTH_H
