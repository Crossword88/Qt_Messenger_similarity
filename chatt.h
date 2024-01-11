#ifndef CHATT_H
#define CHATT_H

#include <QDialog>
#include <iostream>
#include <fstream>
#include <QVector>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QTextEdit>
#include <string>

namespace Ui {
class Chatt;
}

class Chatt : public QDialog
{
    Q_OBJECT

public:
    explicit Chatt(QWidget *parent = nullptr);
    ~Chatt();
    void Chatting();
    QVector <std::string> SomeNames;
    QVector <std::string*> ArrNic;
    QVector <std::string*> ArrMes;

    std::string NickName;
    std::string NameLog;
    std::string* messageC = new std::string;
    int count = 0;
    int* totr;
    QTextEdit* TE;



private slots:
        void ClickedSlot();

private:
    Ui::Chatt *ui;
};

#endif // CHATT_H
