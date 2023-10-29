#ifndef ORDER_H
#define ORDER_H
#include"stock.h"
enum class OrderType {
    BUY,
    SELL,
    BUY_BY_PROFIT // This represents the Limit Order
};


class Order {
protected:
    int m_userID;
    int m_orderID;
    double m_amount; // How much to buy/sell
    double m_price; // For limit orders
    OrderType m_orderType;
    Stock* m_cryptoType;
    static int s_ordercount;

public:
    Order(int userID, double amount, double price,Stock* m_cryptoType,OrderType order);
    virtual ~Order() ;
    // virtual void execute(User* user,double amount,double price, Stock* crypto) = 0; // Pure virtual function for executing the order

    // Getter functions
    int getUserID() const;
    int getOrderID() const;
//    OrderType getOrderType() const;
    double getAmount() const;
    double getPrice() const;

    // Setter functions
    void setUserID(int userID);
    void setOrderID(int orderID);
    void setAmount(double amount);
    void setPrice(double price);
};

#endif // ORDER_H
