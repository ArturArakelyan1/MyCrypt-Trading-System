#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QApplication>
#include "mainwindow.h"

// Function to initialize the database
bool initializeDatabase() {
    QSqlQuery query;

    // Create Users table
    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS Users (
            UserID INTEGER PRIMARY KEY AUTOINCREMENT,
            Name TEXT NOT NULL,
            Surname TEXT NOT NULL,
            Email TEXT UNIQUE NOT NULL,
            Password TEXT NOT NULL
        )
    )")) {
        qCritical() << "Failed to create Users table:" << query.lastError().text();
        return false;
    }

    // Create Balances table
    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS Balances (
            BalanceID INTEGER PRIMARY KEY AUTOINCREMENT,
            UserID INTEGER,
            BalanceUSD REAL DEFAULT 0,
            BalanceCrypto1 REAL DEFAULT 0,
            BalanceCrypto2 REAL DEFAULT 0,
            BalanceCrypto3 REAL DEFAULT 0,
            FOREIGN KEY(UserID) REFERENCES Users(UserID)
        )
    )")) {
        qCritical() << "Failed to create Balances table:" << query.lastError().text();
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/artur/Desktop/Nor 2/user.sqlite");

    if (!db.open()) {
        qCritical() << "Failed to connect to database:" << db.lastError().text();
        return -1;
    }

    if (!initializeDatabase()) {
        qCritical() << "Failed to initialize database tables.";
        return -1;
    }

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
