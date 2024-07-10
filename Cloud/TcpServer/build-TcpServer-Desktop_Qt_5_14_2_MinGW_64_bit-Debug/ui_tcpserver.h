/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QString::fromUtf8("TcpServer"));
        TcpServer->resize(800, 600);
        pushButton = new QPushButton(TcpServer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 160, 121, 71));

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QWidget *TcpServer)
    {
        TcpServer->setWindowTitle(QCoreApplication::translate("TcpServer", "TcpServer", nullptr));
        pushButton->setText(QCoreApplication::translate("TcpServer", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
