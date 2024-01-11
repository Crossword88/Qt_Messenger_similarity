#ifndef MESSAGES_H
#define MESSAGES_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QWidget>
#include <fstream>
#include <thread>
#include <windows.h>
#include "chatt.h"

struct contact
{
    char* name = nullptr;
    char* password = nullptr;
    void create(const char* n, const char* p)
    {
        if (name != nullptr)delete[]name;
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);

        if (password != nullptr)delete[]password;
        password = new char[strlen(p) + 1];
        strcpy_s(password, strlen(p) + 1, p);
    }
};

namespace Ui {
class Messages;
}

class Messages : public QDialog
{
    Q_OBJECT

public:
    explicit Messages(QWidget *parent = nullptr);
    ~Messages();
    void MesMenu ();

        QVector <QPushButton*> button;
        QVBoxLayout *layout;


        std::string mas[255];
        std::string nic[255];
        std::string name;
        int count = 0;
        std::ifstream fin;
        std::ofstream fout;
        QVector <contact*> users;
        QVector <QString*> ArrNic;
        char n[255] = "";
        char p[255] = "";
        int q = 0;
        int ret = 0;
        int qqq = 0;
        int iop = 0;

        int rop = 0;
        QVector <QString*> x;
        std::string nameNick;
        std::string qewrew;
        QString NickName;
        Chatt ch;

private slots:
        void ClickedSlot();

private:
    Ui::Messages *ui;
};

#endif // MESSAGES_H
