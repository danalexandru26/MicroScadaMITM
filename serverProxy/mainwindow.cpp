#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    proxyServerConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::proxyServerConnect(){
    proxyServer = new  QTcpServer(this);

    if(!proxyServer->listen(QHostAddress::LocalHost, 8080)){
        qInfo()<<"Proxy has failed to start\n";
    }
    qInfo()<<"Proxy has connected\n";

    connect(proxyServer, &QTcpServer::newConnection, this, [this]() {
        socketClient = proxyServer->nextPendingConnection();

        socketServer = new QTcpSocket(this);
        socketServer->connectToHost(QHostAddress::LocalHost, 9000);

        if(!socketServer->waitForConnected()){
            qInfo()<<"Proxy cannot connect to central server\n";
        }
        qInfo()<<"Proxy socket has connected to server on port: 9000\n";


        connect(socketServer, &QTcpSocket::readyRead, this, [=]() {
            QByteArray data = socketServer->readAll();
            QString rawData = QString::fromUtf8(data);

            socketClient->write(data);
        });

    });
}
