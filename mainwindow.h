#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: // slots for the button click events
    void on_registerButton_clicked();
    void on_logInButton_clicked();
    void onHelpButtonClicked();

private:
    Ui::MainWindow *ui; // this pointer is used to access the UI elements
};

#endif // MAINWINDOW_H
