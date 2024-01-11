#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileInfo"
#include "QTextStream"
#include "fstream"
#include "iostream"
#include "QFile"
#include "QVector"
#include "messages.h"

void MainWindow::goon()
{
    std::ifstream fin;
    std::ofstream fout;



    for (int i = 0; i <= count; i++)
    {
        if (ui->Log->text().toStdString() == users[i]->name && TextPass.toStdString() == users[i]->password)
        {
            fout.open("Rem.txt");
            if (rem)
                fout <<ui->Log->text().toStdString() <<" " <<ui->Pass->text().toStdString();
            fout.close();
            fout.open("NowName.txt");
            fout <<users[i]->name;
            fout.close();
            mes.show();       //Метод toStdString - преобразование QString в string
        }
    }
        ui->label_3->setText("Login or password is incorrect");
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::ifstream fin;
    std::ofstream fout;

    fin.open("users.txt");
    while (!fin.eof())
            if ((fin.get()) == '\n') count++;
    fin.close();



    fin.open("users.txt");
    char n[255] = "";
        char p[255] = "";
        for (int i = 0; i <= count; i++)
            if (!fin.eof())
            {
                users.push_back(new Contact);
                fin >> n >> p;                  //ошибка в том, что у класса vector есть свои функции через точку. Но класс vector это массив моих классов, из-за этого возникают конфликты, т.к у него есть свои методы через точку, и свойства моего класса тоже там должны быть
                users[i]->create(n, p);                                      //ЕЕЕ, я исправил, хоть ошибка была и не совсем в этом. Короче я забыл что это не массив классов, а массив УКАЗАТЕЛЕЙ на классы
            }
    fin.close();

    std::string imya, familia;
    fin.open("Rem.txt");
    fin >>imya >>familia;
    fin.close();

    for (int i = 0; i <= count; i++)
    {
        if (imya == users[i]->name && familia == users[i]->password)
        {
            fout.open("NowName.txt");
            fout <<users[i]->name;
            fout.close();
            mes.show();       //Метод toStdString - преобразование QString в string
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::ifstream fin;
    std::ofstream fout;

    for (int i = 0; i <= count; i++)
    {
        i = -1;
        if (ui->Log->text().toStdString() == users[i]->name && TextPass.toStdString() == users[i]->password)
        {
            fout.open("NowName.txt");
            fout <<users[i]->name;
            fout.close();
            mes.show();       //Метод toStdString - преобразование QString в string
        }
    }
        ui->label_3->setText("Login or password is incorrect");
}


void MainWindow::on_pushButton_2_clicked()
{
    reg.show();
}


void MainWindow::on_Pass_textChanged(const QString &arg1)   //Слот Вызывается когда в ui->Pass ввелся какой-либо символ
{
    TextPass = arg1;
    QString Entr = "]";
    qInfo() <<TextPass;
    if (TextPass[TextPass.length()-1] == Entr)
    {
        TextPass;
        qInfo() <<TextPass;
        goon();
        ui->Pass->setText("");
    }
    ui->Pass->setEchoMode(QLineEdit::Password);
}



void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 2)
        rem = true;
    else
        rem = false;
    qInfo() <<arg1;
}

