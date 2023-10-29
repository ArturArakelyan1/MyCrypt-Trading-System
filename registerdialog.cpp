#include "registerdialog.h"
#include "ui_registerdialog.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    connect(ui->submitButton, &QPushButton::clicked, this, &RegisterDialog::on_submitRegisterButton_clicked);

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_submitRegisterButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString surname = ui->surnameLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    bool allFieldsFilled = true;

    // Check name
    if (name.isEmpty()) {
        ui->nameLabel->setStyleSheet("color: red");
        allFieldsFilled = false;
    } else {
        ui->nameLabel->setStyleSheet("");  // Reset to default style if previously set to red
    }

    // Check surname
    if (surname.isEmpty()) {
        ui->surnameLabel->setStyleSheet("color: red");
        allFieldsFilled = false;
    } else {
        ui->surnameLabel->setStyleSheet("");
    }

    // Check email
    if (email.isEmpty()) {
        ui->emailLabel->setStyleSheet("color: red");
        allFieldsFilled = false;
    } else {
        ui->emailLabel->setStyleSheet("");
    }

    // Check password
    if (password.isEmpty()) {
        ui->passwordLabel->setStyleSheet("color: red");
        allFieldsFilled = false;
    } else {
        ui->passwordLabel->setStyleSheet("");
    }

    // If any field is empty, return and don't continue with registration
    if (!allFieldsFilled) {
        return;
    }

    // ... rest of the registration logic (email format validation, password hashing, database insertion, etc.)

    QRegularExpression emailRegex(R"((?:[a-zA-Z0-9._%+-]+@(?:mail\.ru|gmail\.com|iclude\.com|inbox\.ru)$))");
    QRegularExpressionMatch match = emailRegex.match(email);

    if (!match.hasMatch()) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return;
    }

    // Hash the password
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Users WHERE Email = ?");
    query.addBindValue(email);
    query.exec();
    query.next();
    int count = query.value(0).toInt();

    if (count > 0) {
        QMessageBox::warning(this, "Registration Failed", "Email already exists.");
        return;
    }

    query.prepare("INSERT INTO Users (Name, Surname, Email, Password) VALUES (?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(surname);
    query.addBindValue(email);
    query.addBindValue(hashedPassword);

    if (!query.exec()) {
        QMessageBox::critical(this, "Registration Failed", "An error occurred during registration.");
        return;
    }

    int userId = query.lastInsertId().toInt();
    query.prepare("INSERT INTO Balances (UserID) VALUES (?)");
    query.addBindValue(userId);
    query.exec();

    QMessageBox::information(this, "Registration", "Successfully Registered!");
    this->close();
}
