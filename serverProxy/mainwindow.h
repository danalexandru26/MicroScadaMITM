#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QByteArray>
#include<QtNetwork/QTcpSocket>
#include<QtNetwork/QTcpServer>
#include<QtNetwork/QHostAddress>
#include<QByteArray>
#include<QMessageBox>

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

private:
    Ui::MainWindow *ui;
    QTcpServer* proxyServer;
    QTcpSocket* socketClient;
    QTcpSocket* socketServer;
};
#endif // MAINWINDOW_H
