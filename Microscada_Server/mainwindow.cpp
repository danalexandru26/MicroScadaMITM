#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->sendDataTrans1, &QPushButton::clicked, this, &MainWindow::onClickSendDataTrans1);
    connect(ui->sendDataTrans2, &QPushButton::clicked, this, &MainWindow::onClickSendDataTrans2);
    connect(ui->dialTrans1, &QDial::valueChanged, this, &MainWindow::onChangeDialTrans1);
    connect(ui->dialTrans2, &QDial::valueChanged, this, &MainWindow::onChangeDialTrans2);
    connect(ui->dialTrans1_2, &QDial::valueChanged, this, &MainWindow::onChangeDialTrans1P);
    connect(ui->dialTrans2_2, &QDial::valueChanged, this, &MainWindow::onChangeDialTrans2P);

    initializeTcpServer();

    QString scadaDiagramSource = ":/symbols/symbols/resources/generator.svg";

    QWidget* parentContainer = qobject_cast<QWidget*>(ui->generator1);

    QSvgWidget* svg = new QSvgWidget(scadaDiagramSource, parentContainer);
    svg->setGeometry(0, 0, parentContainer->width(), parentContainer->height());


    QString scadaDiagramSource2 = ":/symbols/symbols/resources/generator.svg";

    QWidget* parentContainer2 = qobject_cast<QWidget*>(ui->generator2);

    QSvgWidget* svg2 = new QSvgWidget(scadaDiagramSource, parentContainer2);
    svg2->setGeometry(0, 0, parentContainer2->width(), parentContainer2->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeTcpServer(){
    TcpServer = new QTcpServer(this);

    if(!TcpServer->listen(QHostAddress::LocalHost, 9000)){
        qInfo()<<"The server cannot start";
    }
    else{
        qInfo()<<"Server has successfully started listening for clients on: port 9000";
    }

    connect(TcpServer, &QTcpServer::newConnection, this, [=]() {
        client = TcpServer->nextPendingConnection();
        qInfo() << "Client connected";

        connect(client, &QTcpSocket::readyRead, this, [=]() {
            //client sends no data
        });

        connect(client, &QTcpSocket::disconnected, this, [=]() {
            qInfo() << "Client disconnected";
            client->deleteLater();
        });
    });
}

void MainWindow::onClickSendDataTrans1(){
    if(client && client->state() == QAbstractSocket::ConnectedState){
        QString voltage =  QString::number(ui->dialTrans1->value()) + '\n';
        QString power  = QString::number(ui->dialTrans1_2->value());

        QString messageTransformer1 = "transformer1\n" +  voltage + power;
        client->write(messageTransformer1.toUtf8());
        client->flush();
    }
    else{
        qInfo()<<"No client is connected\n";
    }
}

void MainWindow::onClickSendDataTrans2(){
    if(client && client->state() == QAbstractSocket::ConnectedState){
        QString voltage =  QString::number(ui->dialTrans2->value()) + '\n';
        QString power  = QString::number(ui->dialTrans2_2->value());

        QString messageTransformer1 = "transformer2\n" +  voltage + power;
        client->write(messageTransformer1.toUtf8());
        client->flush();
    }
    else{
        qInfo()<<"No client is connected\n";
    }
}

void MainWindow::onChangeDialTrans1(){
    auto labelTrans1 = ui->vTrans1;
    labelTrans1->setText(QString::number(ui->dialTrans1->value()) + " V");

    auto powerGeneratorVoltage = ui->gen1V;

    powerGeneratorVoltage->display(ui->dialTrans1->value());


}

void MainWindow::onChangeDialTrans2(){
    auto labelTrans2 = ui->vTrans2;
    labelTrans2->setText(QString::number(ui->dialTrans2->value()) + " V");

    auto powerGeneratorVoltage = ui->gen2V;

    powerGeneratorVoltage->display(ui->dialTrans2->value());
}

void MainWindow::onChangeDialTrans1P(){
    auto labelTrans1 = ui->vTrans1_2;
    labelTrans1->setText(QString::number(ui->dialTrans1_2->value()) + " W");

    auto powerGeneratorVPower = ui->gen1P;
    powerGeneratorVPower->display(ui->dialTrans1_2->value());
}

void MainWindow::onChangeDialTrans2P(){
    auto labelTrans1 = ui->vTrans2_2;
    labelTrans1->setText(QString::number(ui->dialTrans2_2->value()) + " W");

    auto powerGeneratorVPower = ui->gen2P;
    powerGeneratorVPower->display(ui->dialTrans2_2->value());
}

