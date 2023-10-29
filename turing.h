#ifndef TURING_H
#define TURING_H
//#include <QTimer>

#include "stock.h"

class Turing : public Stock {
public:
    Turing(double base_price);

    // Override the virtual functions from the Stock class
    void PriceGenerator() override;
    int typeId() const override;

private:
//    QTimer* m_priceUpdateTimer;
    static const int s_typeId = 3;
};
#endif // TURING_H
