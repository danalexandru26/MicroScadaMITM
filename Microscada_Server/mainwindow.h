#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QByteArray>
#include<QtNetwork/QTcpSocket>
#include<QtNetwork/QTcpServer>
#include<QtNetwork/QHostAddress>
#include<QByteArray>
#include<QMessageBox>
#include<QtSvgWidgets/QSvgWidget>

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
private:
    void initializeTcpServer();
    void onClickSendDataTrans1();
    void onClickSendDataTrans2();
    void onChangeDialTrans1();
    void onChangeDialTrans2();
    void onChangeDialTrans1P();
    void onChangeDialTrans2P();

private:
    Ui::MainWindow *ui;
    QTcpServer* TcpServer;
    QTcpSocket* client;
};
#endif // MAINWINDOW_H
