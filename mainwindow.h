#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <registration.h>
#include <messages.h>
#include <QDebug>
#include <windows.h>
#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


struct Contact
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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void goon();
    QString TextPass = "";
    bool rem = 0;
     QVector <Contact*> users;
     int count = 0;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Pass_textChanged(const QString &arg1);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Registration reg;
    Messages mes;
};
#endif // MAINWINDOW_H
