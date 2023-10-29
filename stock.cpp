#include "stock.h"

Stock::Stock(int id, double base_price)
   : m_base_price(base_price), m_updated_price(base_price) {
   m_historicalPrices.push_back(base_price);
}

double Stock::getBasePrice() const {
   return m_base_price;
}

void Stock::setBasePrice(double price) {
   m_base_price = price;
}

double Stock::getUpdatedPrice() const {
   return m_updated_price;
}

void Stock::setUpdatedPrice(double price) {
   m_updated_price = price;
   m_historicalPrices.push_back(price);
}

const std::vector<double>& Stock::getHistoricalPrices() const {
   return m_historicalPrices;
}

int Stock::typeId() const {
   return s_typeId;
}

