#include "chatt.h"
#include "ui_chatt.h"
#include "QVector"
#include "fstream"
#include "QLabel"
#include "QTextEdit"
#include "QPushButton"
#include "QVBoxLayout"
#include "QPixmap"
#include "QWidget"
#include "qdynamicbutton.h"
#include "algorithm"

Chatt::Chatt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chatt)
{
    ui->setupUi(this);
    qDebug("qwertrew123456");
    Chatting();
}

Chatt::~Chatt()
{
    delete ui;
}

void Chatt::Chatting()
{
    qDebug("qwertrew123456");
    QVector <QLabel*> label;
    QPushButton* sendit;
    QVBoxLayout *layout;
    std::ifstream fin;
    std::string mas[255];
    std::string nic[255];
    int rt = 0;
    int iop = 0;
    fin.open("users.txt");
    while (!fin.eof())
            if ((fin.get()) == '\n') count++;
    fin.close();
    int q = 0;
    int ret = 0;
    int qqq = 0;
    totr = new int[count];

    fin.open("NameNick.txt");
    fin>>NickName >>NameLog;
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
            ArrNic.push_back(new std::string[qqq]);
            ArrMes.push_back(new std::string[qqq]);
            totr[ret] = qqq;
            qqq = 0;
            for (int j = 0; j < totr[ret]; j++)
            {
                ArrNic[ret][j] = nic[iop];
                ArrMes[ret][j] = mas[iop];
                iop++;
            }
            if (ret < count)    ret++;
        }
    fin.close();
    qDebug("qwertrew123456");
    layout = new QVBoxLayout(this);
    std::string nothing, oneName;
    fin.open("users.txt");
    for (int i = 0; i < count; i++)
            if (!fin.eof())
            {
                fin >>oneName >>nothing;
                SomeNames.push_back(oneName);
            }
    fin.close();

    for (int i = 0; i < count; i++)
        for (int j = 0; j < totr[i]; j++)
        {
            qDebug("Somee");
            if (SomeNames[i] == NickName && ArrNic[i][j] == NameLog)
            {
                qDebug("qwertrew123456TOPPPP1111");
                    label.push_back(new QLabel((ArrNic[i][j] + ": " + ArrMes[i][j]).c_str()));
                layout->addWidget(label[rt]);
                rt++;
            }
            else if (SomeNames[i] == NameLog && ArrNic[i][j] == NickName)
            {
                qDebug("qwertrew123456TOPPPP22222");
                    label.push_back(new QLabel((ArrNic[i][j] + ": "  + ArrMes[i][j]).c_str()));
                layout->addWidget(label[rt]);
                rt++;
            }
        }
    TE = new QTextEdit;
    sendit = new QPushButton("Send");
    layout->addWidget(TE);
    layout->addWidget(sendit);

    connect(sendit, &QPushButton::clicked, this, &Chatt::ClickedSlot);

    qDebug("Sergey");

}



void Chatt::ClickedSlot()
{
    *messageC = TE->toPlainText().toStdString();
    for (int j = 0; j < count; j++)
        for (int i = 0; i < totr[j]; i++)
            if (NickName == SomeNames[j])
            {
                std::string* nick = new std::string[totr[j]];
                std::string* masa = new std::string[totr[j]];
                for (int u = 0; u < totr[j]; u++)
                {
                    nick[u] = ArrNic[j][u];
                    masa[u] = ArrMes[j][u];
                }
                ArrMes[j] = new std::string[totr[j]+1];
                ArrNic[j] = new std::string[totr[j]+1];
                for (int l = 0; l <= totr[j]; l++)
                {
                    if (l != totr[j])
                    {
                        ArrNic[j][l] = nick[l];
                        ArrMes[j][l] = masa[l];
                    }
                    else if (l == totr[j])
                    {
                        ArrNic[j][l] = NameLog;
                        ArrMes[j][l] = *messageC;
                    }
                }
                totr[j]++;
                delete[] nick;
                delete[] masa;
                goto endd;
            }
    endd:
    qDebug("Expect us");
    std::ofstream fout;
    fout.open("messages.txt");
    for (int i = 0; i < count; i++)
        {
            for (int b = 0; b < totr[i]; b++)
            {
                if (b >= 1)
                    fout << std::endl;
                fout << ArrNic[i][b] <<" " << ArrMes[i][b];
            }
            if (i + 1 == count) break;
            fout << std::endl <<" " << std::endl;
        }
    fout.close();
}

