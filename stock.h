#ifndef STOCK_H
#define STOCK_H
#include <vector>


class Stock {
protected:
    double m_base_price;
    double m_updated_price;
    static const int s_typeId = 0;
    std::vector<double> m_historicalPrices; // could alternatively be a map of timestamps to prices
public:
    Stock(int id, double base_price);
    // Getter and Setter for Base Price
    double getBasePrice() const;
    void setBasePrice(double price);

    // Getter and Setter for Updated Price
    double getUpdatedPrice() const ;
    void setUpdatedPrice(double price) ;
    virtual int typeId() const;
    // Getter for Historical Prices
    const std::vector<double>& getHistoricalPrices() const ;

    // Virtual function for price generation
    virtual void PriceGenerator() = 0; // pure virtual function
    virtual ~Stock() = default; // Virtual destructor for base class
};

#endif // STOCK_H
