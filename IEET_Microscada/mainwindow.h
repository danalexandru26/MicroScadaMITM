#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QtSvgWidgets/QSvgWidget>
#include<QRandomGenerator>
#include<QtNetwork/QTcpSocket>
#include<QtNetwork/QHostAddress>
#include<QByteArray>
#include<QMessageBox>

#include"powernode.h"

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
    void drawBasicMicroScada();
    void simulationStep();
    void assignPowerNodes(QList<PowerNode*>& nodeList, QLCDNumber* voltage, QLCDNumber* power, int percentage);
    void initializeTCPSocket();

private:
    Ui::MainWindow *ui;

    PowerNode* parentLineA;
    PowerNode* parentLineB;
    QList<PowerNode*> powerDistributionA{};
    QList<PowerNode*> powerDistributionB{};

    QTcpSocket* TcpSocket;


};
#endif // MAINWINDOW_H
