#include "user.h"


int User::getBalance() const {
    return m_balanceUSd;
}
int User::getUserId() const{
    return m_userId;
}
int User::getCryptoCount( Stock* type)  {
    auto it = m_cryptoBalance.find(type);
    if (it != m_cryptoBalance.end()) {
        return it->second;
    }
    return 0.0;
}
std::string User::getName() const {
    return m_name;
}

std::string User::getSurName() const {
    return m_surname;
}

void User::setName(const std::string& name){
    m_name = name;
}
void User::setSurName(const std::string& surname) {
    m_surname = surname;
}
void User::setUserId(int id){
    m_userId = id;
}

void User::setBalance(double balance) {
    m_balanceUSd = balance;
}

void User::setCryptoCount(Stock* crypto, double count) {
    if (count < 0) {
        std::cerr << "Error: The crypto count cannot be negative." << std::endl;
        return;
    }

    m_cryptoBalance[crypto] = count;
}

void User::Buy(Stock* crypttpye, double count){
    double cost =  count * crypttpye->getUpdatedPrice();
    if(cost > m_balanceUSd){
        //error
    }
    m_balanceUSd -= cost;
    setCryptoCount(crypttpye,getCryptoCount(crypttpye) + count);
    m_orderList.push_back(new Order(m_userId,count,crypttpye->getUpdatedPrice(),crypttpye,OrderType::BUY));
}

void User::Sell(Stock* crypttype,int count){
    if(count > getCryptoCount(crypttype)){
        //error
    }
    double cost = count * crypttype->getUpdatedPrice();
    m_balanceUSd+= cost;
    setCryptoCount(crypttype,getCryptoCount(crypttype) - count);

    m_orderList.push_back(new Order(m_userId,count,crypttype->getUpdatedPrice(),crypttype,OrderType::SELL));
}


void User::PushToDB() {
    QSqlQuery query;

    // Prepare an SQL query to update the user's balance in the Balances table
    query.prepare(R"(
        UPDATE Balances
        SET BalanceUSD = :balanceUSD
        WHERE UserID = :userID
    )");
    query.bindValue(":balanceUSD", m_balanceUSd);
    query.bindValue(":userID", m_userId);

    // Execute the query
    if (!query.exec()) {
        qCritical() << "Failed to update user balance:" << query.lastError().text();
    }

    // Update the stock counts in the Balances table
    for (const auto& entry : m_cryptoBalance) {
        Stock* stock = entry.first;
        double stockCount = entry.second;

        // Assuming you have a method in Stock to get its type ID
        int stockTypeId = stock->typeId();

        // Prepare an SQL query to update the stock count in the Balances table
        query.prepare("UPDATE Balances SET BalanceCrypto" + QString::number(stockTypeId) +
                    " = :stockCount WHERE UserID = :userID");
        query.bindValue(":stockCount", stockCount);
        query.bindValue(":userID", m_userId);


        // Execute the query
        if (!query.exec()) {
            qCritical() << "Failed to update stock count:" << query.lastError().text();
        }
    }
}

