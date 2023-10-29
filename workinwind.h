#ifndef WORKINWIND_H
#define WORKINWIND_H
#include"ada.h"
#include"knuth.h"
#include"turing.h"
#include"user.h"
#include<QTimer>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
//using namespace QtCharts;

namespace Ui {
class workinwind;
}

class workinwind : public QDialog
{
    Q_OBJECT

public:
    explicit workinwind(QWidget *parent = nullptr);
    ~workinwind();
    void updateAda();
    void updateKnuth();
    void updateTuring();
    void updatePrices();
    void setUserId(int userId);
    void setUser(int);
private:
    int m_userId;
    Ui::workinwind *ui;
    Ada* m_ada;
    Knuth* m_knuth;
    Turing* m_turing;
    User* m_user;
};

#endif // WORKINWIND_H
