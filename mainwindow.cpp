#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "registerdialog.h"
#include "logindialog.h"
#include "helpdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap logo(":/images/Logo.png");
    ui->label->setPixmap(logo.scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    connect(ui->registerButton, SIGNAL(clicked()), this, SLOT(someSlotName()));
    connect(ui->helpButton, &QPushButton::clicked, [=](){
        HelpDialog helpDialog(this);
        helpDialog.exec();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::onRegisterButtonClicked()
//{
//    // Code to execute when the Register button is clicked
//    qDebug() << "Register button clicked!";
//}

void MainWindow::on_logInButton_clicked() {
    LoginDialog loginDialog(this);
    if (loginDialog.exec() == QDialog::Accepted) {
        // Handle successful login here
    }
}


void MainWindow::onHelpButtonClicked()
{
    // Create an instance of the HelpDialog
    HelpDialog helpDialog(this); // 'this' is passed to set MainWindow as the parent of HelpDialog

    // Display the dialog modally
    helpDialog.exec();
}


void MainWindow::on_registerButton_clicked()
{
    RegisterDialog registerDialog(this); // Create the dialog
    registerDialog.exec(); // Show the dialog as modal
}
