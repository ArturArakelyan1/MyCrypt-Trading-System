
#include "orderbook.h"

void FIFOOrderMatchingStrategy::matchOrders(std::list<Order>& buyOrders, std::list<Order>& sellOrders) {
    auto buyIter = buyOrders.begin();
    auto sellIter = sellOrders.begin();

    while (buyIter != buyOrders.end() && sellIter != sellOrders.end()) {
        if (buyIter->getPrice() >= sellIter->getPrice()) {
            // Execute trade (for simplicity, just removing the orders)
            buyOrders.erase(buyIter++);
            sellOrders.erase(sellIter++);
        } else {
            break;
        }
    }
}

OrderBook::OrderBook() : matchingStrategy(std::make_unique<FIFOOrderMatchingStrategy>()) {}

OrderBook::~OrderBook() = default;

void OrderBook::setMatchingStrategy(std::unique_ptr<IOrderMatchingStrategy> strategy) {
    matchingStrategy = std::move(strategy);
}

void OrderBook::addOrder(const Order& order) {
    if (order.getOrderType() == OrderType::BUY) {
        buyOrders.push_back(order);
        buyOrders.sort([](const Order& a, const Order& b) { return a.getPrice() > b.getPrice(); });
    } else if (order.getOrderType() == OrderType::SELL) {
        sellOrders.push_back(order);
        sellOrders.sort([](const Order& a, const Order& b) { return a.getPrice() < b.getPrice(); });
    }
}

void OrderBook::matchOrders() {
    if (matchingStrategy) {
        matchingStrategy->matchOrders(buyOrders, sellOrders);
    } else {
        throw std::runtime_error("Order matching strategy not set");
    }
}
