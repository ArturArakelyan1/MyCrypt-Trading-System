#include "helpdialog.h"
#include "ui_helpdialog.h"
#include <QDesktopServices>
#include <QUrl>

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);

    // Set the predefined text to the QTextEdit in HelpDialog
    QString predefinedText = R"(
    About Our Program:

    Our program is a parallel of Binance - a comprehensive stock trading system where multiple traders can buy and sell stocks. Designed to provide a seamless trading experience, our platform ensures transparency, security, and ease of use.

    Getting Support:

    If you encounter any issues or have questions about our platform, please don't hesitate to contact our support team. You can reach out to us via the 'Contact Support' button below or by emailing us directly at support@example.com. Our team is always here to assist you!
    )";

    ui->textEdit->setPlainText(predefinedText);

    // Connect the Contact Support button's clicked signal to its slot
    connect(ui->contactSupportButton, &QPushButton::clicked, this, &HelpDialog::on_contactSupportButton_clicked);
}


HelpDialog::~HelpDialog()
{
    delete ui;
}
void HelpDialog::on_contactSupportButton_clicked()
{
    // Open the default email client with predefined content:
    QDesktopServices::openUrl(QUrl("mailto:support@example.com?subject=App Support Request&body=Hello, I need help with..."));
}

//void HelpDialog::on_contactButton_clicked()
//{
//    QDesktopServices::openUrl(QUrl("mailto:support@yourapp.com?subject=Support Request"));
//}
