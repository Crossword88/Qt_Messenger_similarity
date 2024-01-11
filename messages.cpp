#include "messages.h"
#include "ui_messages.h"
#include "QVector"
#include "fstream"
#include "QPushButton"
#include "QVBoxLayout"
#include "QPixmap"
#include "QWidget"
#include "qdynamicbutton.h"
#include "algorithm"
#include "chatt.h"
#include "QThread"
#include "QDebug"


Messages::Messages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Messages)
{
    ui->setupUi(this);

    MesMenu();

}


Messages::~Messages()
{
    delete ui;
}

void Messages::MesMenu()
{

    fin.open("NowName.txt");
    fin>>name;          //Ошибка тут в том, что я это всё делаю грубо говоря в конструкторе, поэтому в name списывается не измененная переменная
    fin.close();

        fin.open("users.txt");
        while (!fin.eof())
                if ((fin.get()) == '\n') count++;
        fin.close();

        int totr[count];

        fin.open("users.txt");
            for (int i = 0; i <= count; i++)
                if (!fin.eof())
                {
                    users.push_back(new contact);
                    fin >> n >> p;                  //ошибка в том, что у класса vector есть свои функции через точку. Но класс vector это массив моих классов, из-за этого возникают конфликты, т.к у него есть свои методы через точку, и свойства моего класса тоже там должны быть
                    users[i]->create(n, p);                                      //ЕЕЕ, я исправил, хоть ошибка была и не совсем в этом. Короче я забыл что это не массив классов, а массив УКАЗАТЕЛЕЙ на классы
                }
        fin.close();


    fin.open("messages.txt");
    while (!fin.eof())
    {
        fin >> nic[q];
        fin.ignore();
        std::getline(fin, mas[q]);
        q++;
        qqq++;
        char poi = fin.get();
        while (poi != ' ' && !fin.eof())
        {
            fin >> nic[q];
            fin.ignore();
            std::getline(fin, mas[q]);
            qqq++;
            nic[q] = poi + nic[q];
            q++;
            poi = fin.get();
        }
        ArrNic.push_back(new QString[qqq]);
        totr[ret] = qqq;
        qqq = 0;
        for (int j = 0; j < totr[ret]; j++)
        {
            ArrNic[ret][j] = nic[iop].c_str();
            iop++;
        }
        if (ret < count)    ret++;
    }
    fin.close();

    QVector<QString> arrbut;
    for (int i = 0; i < count; i++)
        for (int j = 0; j < totr[i]; j++)
            if (name == users[i]->name)
            {
                arrbut.push_back(QString(ArrNic[i][j]));
            }

    /*QString arr[2] = {"Privet", "Hello"};
     *
    ui->label->setText("wfesgsf");
    ui->label_2->setText(arr[1]);
    layout = new QVBoxLayout(this);
    for (int i = 0; i < 2; i++)
    {

        button.push_back(new QPushButton);
        button[i] = new QPushButton(arr[i]);
        layout->addWidget(button[i]);

    }*/

    int tmp = arrbut.size();
    for (int i = 0; i < tmp; i++)
        for (int j = 0; j < tmp; j++)
            if(i != j)
                if (arrbut[i] == arrbut[j])
                {
                    swap(arrbut[tmp - 1], arrbut[j]);
                    tmp--;
                }

    int rt = 0;
    layout = new QVBoxLayout(this);
    for (int i = 0; i < tmp; i++)
        {
                button.push_back(new QPushButton(arrbut[i]));
                layout->addWidget(button[rt]);
                rt++;
//            ui->label->setText(name.c_str());
//            ui->label_2->setText(users[i]->name);
        }



    for (int i = 0; i < button.size(); i++)
    {
        connect(button[i], &QPushButton::clicked, this, &Messages::ClickedSlot);

    }

}

void Messages::ClickedSlot()
{
    HWND hWnd = FindWindowA("Qt632QWindowIcon", NULL);
    ShowWindow(hWnd, SW_HIDE);
    Sleep(1000);
    QDynamicButton *button1 = (QDynamicButton*) sender();
    NickName = button1->text();
    qInfo() <<NickName;
    fout.open("NameNick.txt");
    fout << NickName.toStdString() <<" " <<name;
    fout.close();
    ch.show();
}







