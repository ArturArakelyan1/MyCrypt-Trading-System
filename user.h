#ifndef USER_H
#define USER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<iostream>
#include<list>
#include <unordered_map>
#include"order.h"


class User {
    std::string m_name;
    std::string m_surname;
    int m_userId;
    double m_balanceUSd;
    std::unordered_map<Stock*,double> m_cryptoBalance;
    std::list<Order*> m_orderList;
public:
    //Getters
    int getBalance() const;
    std::string getName() const;
    std::string getSurName() const;
    int getUserId() const;
    int getCryptoCount( Stock* type) ;

    //Setters
    void setName(const std::string&);
    void setSurName(const std::string&);
    void setUserId(int);
    void setBalance(double);
    void setCryptoCount(Stock* crypto,double count);

    void Buy(Stock* crypttpye, double count);
    void Sell(Stock* crypttype,int count);//cryptype is the type of the cryptovalue
    // void BuyByProfit(Stock* crypttype, int count, int priceToSell);// for Limit Order
    // void leave(); // this function should be called when the user push the exit butten to send the user info to db, like the balance
    void PushToDB();//to push the user info into the data using the user id every 3 seconds
};

#endif // USER_H
