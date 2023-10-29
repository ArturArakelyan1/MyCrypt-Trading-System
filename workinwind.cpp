#include "workinwind.h"
#include "ui_workinwind.h"

workinwind::workinwind(QWidget *parent) :
    QDialog(parent),
     ui(new Ui::workinwind),
     m_ada(new Ada(12)),
     m_knuth(new Knuth(23)),
     m_turing(new Turing(15)),
//     m_user(new User()),
     m_userId(-1)
//    Create a QTimer for updating prices every 3 seconds
{
    ui->setupUi(this);
     QTimer* priceUpdateTimer = new QTimer(this);
     connect(priceUpdateTimer, &QTimer::timeout, this, &workinwind::updatePrices);
     qDebug() << "UserID in window:" << m_userId;
     priceUpdateTimer->start(2000);  // 3000 milliseconds (3 seconds)
}

workinwind::~workinwind()
{
    delete m_ada;
    delete m_knuth;
    delete m_turing;
    delete m_user;
    delete ui;
}

void workinwind::updateAda()
{
    double courent = m_ada->getUpdatedPrice();
    m_ada->PriceGenerator();
    double percentageChange = ((m_ada->getUpdatedPrice() - courent) / courent) * 100.0;
    ui->priceCrypt1->setText(QString::number(percentageChange, 'f', 2) + "%");

    // Update the color based on the percentage change
    if (percentageChange >= 0) {
        // Price is growing, set color to green
        ui->priceCrypt1->setStyleSheet("QLabel { color: green; }");
    } else if (percentageChange < 0) {
        // Price is going down, set color to red
        ui->priceCrypt1->setStyleSheet("QLabel { color: red; }");
    }
}

void workinwind::updateKnuth()
{
    double courent = m_knuth->getUpdatedPrice();
    m_knuth->PriceGenerator();
    double percentageChange = ((m_knuth->getUpdatedPrice() - courent) / courent) * 100.0;
    ui->priceCrypt2->setText(QString::number(percentageChange, 'f', 2) + "%");
    // Update the color based on the percentage change
    if (percentageChange >= 0) {
        // Price is growing, set color to green
        ui->priceCrypt2->setStyleSheet("QLabel { color: green; }");
    } else if (percentageChange < 0) {
        // Price is going down, set color to red
        ui->priceCrypt2->setStyleSheet("QLabel { color: red; }");
    }
}

void workinwind::updateTuring()
{
    double courent = m_turing->getUpdatedPrice();
    m_turing->PriceGenerator();
    double percentageChange = ((m_turing->getUpdatedPrice() - courent) / courent) * 100.0;
    ui->priceCrypt3->setText(QString::number(percentageChange, 'f', 2) + "%");
    // Update the color based on the percentage change
    if (percentageChange >= 0) {
        // Price is growing, set color to green
        ui->priceCrypt3->setStyleSheet("QLabel { color: green; }");
    } else if (percentageChange < 0) {
        // Price is going down, set color to red
        ui->priceCrypt3->setStyleSheet("QLabel { color: red; }");
    }
}
void workinwind::updatePrices()
{

    updateAda();
    updateKnuth();
    updateTuring();

}
//void workinwind::setUser(int userId){
//    QSqlQuery query;
//    query.prepare("SELECT * FROM Users WHERE UserID = :userId");
//    query.bindValue(":userId", userId);

//    if (!query.exec()) {
//        qCritical() << "Failed to fetch user information:" << query.lastError().text();
//        return;
//    }

//    if (query.next()) {
//        // Retrieve user details from the query result
//        QString name = query.value("Name").toString();
//        QString surname = query.value("Surname").toString();

//        // Create a User object and set its properties
//        User* user = new User();
//        user->setName(name.toStdString());
//        user->setSurName(surname.toStdString());
//        user->setUserId(userId);

//        // Assign the user to the member variable m_user
//        m_user = user;

//        // Now you can use the 'm_user' object as needed
//        // For example, update UI elements with user information
//    } else {
//        qWarning() << "User not found with ID:" << userId;
//    }
//}




void workinwind::setUserId(int userId){
    m_userId = userId;
}





