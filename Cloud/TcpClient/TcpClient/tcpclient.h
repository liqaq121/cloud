#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

    void loadConfig();
public slots:
    void onConnected();
    void onRecvMsg();
private slots:
    //void on_btnSend_clicked();

    void on_btnLogin_clicked();

    void on_btnRegister_clicked();

private:
    Ui::TcpClient *ui;
    QTcpSocket m_tcpSocket;
    QString m_strIP;
    quint16 m_port;
};
#endif // TCPCLIENT_H
