#include "order.h"

int Order::s_ordercount = 0;
Order::Order(int userID, double amount, double price,Stock* cryptoType,OrderType type )
    : m_userID(userID), m_amount(amount), m_price(price), m_orderType(type), m_cryptoType(cryptoType)  {
    m_orderID = ++s_ordercount;
}

int Order::getUserID() const {
    return m_userID;
}

int Order::getOrderID() const {
    return m_orderID;
}

double Order::getAmount() const {
    return m_amount;
}

double Order::getPrice() const {
    return m_price;
}

void Order::setUserID(int userID) {
    m_userID = userID;
}

void Order::setOrderID(int orderID) {
    m_orderID = orderID;
}


void Order::setAmount(double amount) {
    m_amount = amount;
}

void Order::setPrice(double price) {
    m_price = price;
}
