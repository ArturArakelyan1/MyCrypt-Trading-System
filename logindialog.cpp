#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QDebug>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    connect(ui->submitButton, &QPushButton::clicked, this, &LoginDialog::on_submitButton_clicked);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

//void LoginDialog::on_submitButton_clicked()
//{/*
//    qDebug() << "Submit button clicked";
//    QString email = ui->usernameLineEdit->text();
//    QString password = ui->passwordLineEdit->text();

//    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

//    QSqlQuery query;
//    query.prepare("SELECT COUNT(*) FROM Users WHERE Email = ? AND Password = ?");
//    query.addBindValue(email);
//    query.addBindValue(hashedPassword);
//    query.exec();
//    query.next();
//    int count = query.value(0).toInt();

//    if (count == 1) {
//        qDebug() << "Login successful";
//        WorkingWindow *workingWindow = new WorkingWindow();
//        workingWindow->setAttribute(Qt::WA_DeleteOnClose);  // Ensure the window gets deleted on close
//        workingWindow->setUserInformation(email);  // Pass user info to WorkingWindow
//        workingWindow->show();
//        accept();  // Close the login window
//    } else {
//        qDebug() << "Login failed";
//        QMessageBox::warning(this, "Login Failed", "Incorrect email or password.");
//    }*/
//}

////working one
//void LoginDialog::on_submitButton_clicked()
//{
//    qDebug() << "Submit button clicked";
//    QString email = ui->usernameLineEdit->text();
//    QString password = ui->passwordLineEdit->text();

//    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

//    QSqlQuery query;
//    query.prepare("SELECT COUNT(*) FROM Users WHERE Email = ? AND Password = ?");
//    query.addBindValue(email);
//    query.addBindValue(hashedPassword);
//    query.exec();
//    query.next();
//    int count = query.value(0).toInt();

//    if (count == 1) {
//        qDebug() << "Login successful";
//        workinwind *window = new workinwind();
//        window->setAttribute(Qt::WA_DeleteOnClose);  // Ensure the window gets deleted on close
//        // window->setUserInformation(email);  // Pass user info to workinwind, if needed
//        window->show();
//        this->hide();  // Optionally, hide the login window
//    } else {
//        qDebug() << "Login failed";
//        QMessageBox::warning(this, "Login Failed", "Incorrect email or password.");
//    }
//}

void LoginDialog::on_submitButton_clicked()
{
    qDebug() << "Submit button clicked";
    QString email = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    QSqlQuery query;
    query.prepare("SELECT UserID FROM Users WHERE Email = ? AND Password = ?");
    query.addBindValue(email);
    query.addBindValue(hashedPassword);
    query.exec();

    if (query.next()) {
        int userId = query.value(0).toInt();
        qDebug() << "Login successful for UserID:" << userId;

        workinwind *window = new workinwind();
        window->setAttribute(Qt::WA_DeleteOnClose);
        window->setUserId(userId);  // Pass the UserID to the workinwind window
        window->show();
        this->hide();
    } else {
        qDebug() << "Login failed";
        QMessageBox::warning(this, "Login Failed", "Incorrect email or password.");
    }
}
