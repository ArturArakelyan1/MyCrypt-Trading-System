
#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <list>
#include <memory>
#include "order.h"

class IOrderMatchingStrategy {
public:
    virtual ~IOrderMatchingStrategy() = default;
    virtual void matchOrders(std::list<Order>& buyOrders, std::list<Order>& sellOrders) = 0;
};

class FIFOOrderMatchingStrategy : public IOrderMatchingStrategy {
public:
    virtual void matchOrders(std::list<Order>& buyOrders, std::list<Order>& sellOrders) override;
};

class OrderBook {
private:
    std::unique_ptr<IOrderMatchingStrategy> matchingStrategy;
    std::list<Order> buyOrders;
    std::list<Order> sellOrders;
    
public:
    OrderBook();
    ~OrderBook();

    void setMatchingStrategy(std::unique_ptr<IOrderMatchingStrategy> strategy);
    void addOrder(const Order& order);
    void matchOrders();
};

#endif // ORDERBOOK_H
