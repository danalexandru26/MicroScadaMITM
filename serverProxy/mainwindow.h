#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QByteArray>
#include<QtNetwork/QTcpSocket>
#include<QtNetwork/QTcpServer>
#include<QtNetwork/QHostAddress>
#include<QByteArray>
#include<QMessageBox>
#include<QFile>
#include<QSslSocket>
#include<QSslKey>
#include<QSslConfiguration>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void proxyServerConnect();
        void proxyClientConnect();
    QSslConfiguration buildCertificates();

    void displayValues(QString& payload);
    void connectEvents();

    void onPressAlterValuesT1();
    void onPressAlterValuesT2();

private:
    Ui::MainWindow *ui;
    QTcpServer* proxyServer;

    QSslSocket* socketServer;
    QSslSocket* sslConnectionWrapper;
};
#endif // MAINWINDOW_H
