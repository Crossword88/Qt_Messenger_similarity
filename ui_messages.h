/********************************************************************************
** Form generated from reading UI file 'messages.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Messages
{
public:

    void setupUi(QDialog *Messages)
    {
        if (Messages->objectName().isEmpty())
            Messages->setObjectName(QString::fromUtf8("Messages"));
        Messages->resize(560, 274);

        retranslateUi(Messages);

        QMetaObject::connectSlotsByName(Messages);
    } // setupUi

    void retranslateUi(QDialog *Messages)
    {
        Messages->setWindowTitle(QCoreApplication::translate("Messages", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Messages: public Ui_Messages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGES_H
