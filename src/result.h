#ifndef RESULT_H
#define RESULT_H
#include <QString>
#include <QDialog>
#include "QMessageBox"
#include "QFile"
#include "iostream"
#include <QTextStream>
#include <QVector>
#include <Qdir>
namespace Ui {
class result;
}

class result : public QDialog
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    QString aa,bb;
    ~result();
public slots:
    void setscore(int a);
signals:
    void exit();
    void restart();
    void ok();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

private:
    Ui::result *ui;
};

#endif // RESULT_H
