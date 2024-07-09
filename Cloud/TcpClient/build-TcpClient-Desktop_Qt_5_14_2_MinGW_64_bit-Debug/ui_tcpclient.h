/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QLabel *label;
    QLineEdit *editName;
    QPushButton *btnLogin;
    QPushButton *btnRegister;
    QLabel *label_2;
    QLineEdit *editPwd;
    QPushButton *btnCancel;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QString::fromUtf8("TcpClient"));
        TcpClient->resize(550, 428);
        label = new QLabel(TcpClient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 90, 80, 26));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\234\236\351\271\234\346\226\207\346\245\267"));
        font.setPointSize(18);
        label->setFont(font);
        editName = new QLineEdit(TcpClient);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setGeometry(QRect(190, 90, 251, 41));
        btnLogin = new QPushButton(TcpClient);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(190, 210, 171, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\234\236\351\271\234\346\226\207\346\245\267"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        btnLogin->setFont(font1);
        btnRegister = new QPushButton(TcpClient);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setGeometry(QRect(110, 280, 111, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\234\236\351\271\234\346\226\207\346\245\267"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setWeight(50);
        btnRegister->setFont(font2);
        label_2 = new QLabel(TcpClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 150, 80, 27));
        label_2->setFont(font);
        editPwd = new QLineEdit(TcpClient);
        editPwd->setObjectName(QString::fromUtf8("editPwd"));
        editPwd->setGeometry(QRect(190, 150, 251, 41));
        editPwd->setEchoMode(QLineEdit::Password);
        btnCancel = new QPushButton(TcpClient);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(320, 280, 111, 41));
        btnCancel->setFont(font2);

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "TcpClient", nullptr));
        label->setText(QCoreApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215:", nullptr));
        btnLogin->setText(QCoreApplication::translate("TcpClient", "\347\231\273\345\275\225", nullptr));
        btnRegister->setText(QCoreApplication::translate("TcpClient", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("TcpClient", "\345\257\206   \347\240\201:", nullptr));
        btnCancel->setText(QCoreApplication::translate("TcpClient", "\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
