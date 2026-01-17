#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectEvents();
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

            displayValues(rawData);
            socketClient->write(data);
        });

    });
}

void MainWindow::displayValues(QString& payload){
    QTextEdit* labelTransformer1Voltage = ui->labelT1V;
    QTextEdit* labelTransformer1Power = ui->labelT1P;

    QTextEdit* labelTransformer2Voltage = ui->labelT2V;
    QTextEdit* labelTransformer2Power = ui->labelT2P;

    QStringList list = payload.split('\n');

    if(list.size() < 3){
        qInfo()<<"Invalid data format\n";
        return;
    }

    if(list[0] == "transformer1"){
        labelTransformer1Voltage->setText(list[1] + 'V');
        labelTransformer1Power->setText(list[2] + 'W');
    }
    else if(list[0] == "transformer2"){
        labelTransformer2Voltage->setText(list[1] + 'V');
        labelTransformer2Power->setText(list[2] + 'W');
    }
    else{
        qInfo()<<"Invalid payload header\n";
        return;
    }
}

void MainWindow::connectEvents(){
    connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::onPressAlterValuesT1);
    connect(ui->pushButton_2, &QPushButton::pressed, this, &MainWindow::onPressAlterValuesT2);
}

void MainWindow::onPressAlterValuesT1(){
    QString transformer1Voltage = ui->labelT1V_Proxy->toPlainText();
    QString transformer1Power = ui->labelT1P_Proxy->toPlainText();

    QString transformer2Voltage = ui->labelT2V_Proxy->toPlainText();
    QString transformer2Power = ui->labelT2P_Proxy->toPlainText();

    if(socketClient && socketClient->state() == QAbstractSocket::ConnectedState){
        if(transformer1Voltage.length() > 0 && transformer1Power.length() > 0){
            QString data = "transformer1\n" + transformer1Voltage + "\n" + transformer1Power+"\n";

            socketClient->write(data.toUtf8());
        }
    }
    else{
        qInfo()<<"Socket is not active!\n";
    }

    if(socketClient && socketClient->state() == QAbstractSocket::ConnectedState){
        if(transformer2Voltage.length() > 0 && transformer2Power.length() > 0){
            QString data = "transformer2\n" + transformer2Voltage + "\n" + transformer2Power +"\n";

            socketClient->write(data.toUtf8());
        }
    }
    else{
        qInfo()<<"Socket is not active!\n";
    }
}

void MainWindow::onPressAlterValuesT2(){
    QString transformer2Voltage = ui->labelT2V_Proxy->toPlainText();
    QString transformer2Power = ui->labelT2P_Proxy->toPlainText();

    if(socketClient && socketClient->state() == QAbstractSocket::ConnectedState){
        if(transformer2Voltage.length() > 0 && transformer2Power.length() > 0){
            QString data = "transformer2\n" + transformer2Voltage + "\n" + transformer2Power +"\n";

            socketClient->write(data.toUtf8());
        }
    }
    else{
        qInfo()<<"Socket is not active!\n";
    }
}

