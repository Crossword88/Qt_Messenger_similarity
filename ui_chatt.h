/********************************************************************************
** Form generated from reading UI file 'chatt.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATT_H
#define UI_CHATT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Chatt
{
public:

    void setupUi(QDialog *Chatt)
    {
        if (Chatt->objectName().isEmpty())
            Chatt->setObjectName(QString::fromUtf8("Chatt"));
        Chatt->resize(400, 300);

        retranslateUi(Chatt);

        QMetaObject::connectSlotsByName(Chatt);
    } // setupUi

    void retranslateUi(QDialog *Chatt)
    {
        Chatt->setWindowTitle(QCoreApplication::translate("Chatt", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chatt: public Ui_Chatt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATT_H
