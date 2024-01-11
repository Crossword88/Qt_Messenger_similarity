#include "registration.h"
#include "ui_registration.h"
#include "fstream"
#include "mainwindow.h"
#include "QVector"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_clicked()
{
    std::ofstream fout;
    std::ifstream fin;
    int count = 0;
    fin.open("users.txt");
    std::string x, y;
    while (!fin.eof())
        if ((fin.get()) == '\n') count++;
    fin.close();
    fin.open("users.txt");
    bool z = false;
    for (int i = 0; i <= count; i++)
    {
        fin >>x >>y;
        if (x == ui->name->text().toStdString() && y == ui->newPass->text().toStdString())
            z = true;

    }
    fin.close();
    if (z == false)
    {
        fout.open("users.txt", std::ofstream::app);
        fout << std::endl <<ui->name->text().toStdString() << " " << ui->newPass->text().toStdString();
        fout.close();
        close();
    }
    else ui->label_3->setText("That account is already here");
}

