#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"powernode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLCDNumber* parentVoltageA = qobject_cast<QLCDNumber*>(ui->trafo1V);
    QLCDNumber* parentPowerA = qobject_cast<QLCDNumber*>(ui->trafo1P);
    parentLineA = new PowerNode(parentVoltageA, parentPowerA, this);

    QLCDNumber* parentVoltageB = qobject_cast<QLCDNumber*>(ui->trafo2V);
    QLCDNumber* parentPowerB = qobject_cast<QLCDNumber*>(ui->trafo2P);
    parentLineB = new PowerNode(parentVoltageB, parentPowerB, this);

    auto capacitorBank1V = qobject_cast<QLCDNumber*>(ui->capBankV1);
    auto capacitorBank1P = qobject_cast<QLCDNumber*>(ui->capBankP1);
    assignPowerNodes(powerDistributionA, capacitorBank1V, capacitorBank1P, 10);

    auto ext1V = qobject_cast<QLCDNumber*>(ui->extV);
    auto ext1P = qobject_cast<QLCDNumber*>(ui->extP);
    assignPowerNodes(powerDistributionA, ext1V, ext1P, 20);

    auto ext2V = qobject_cast<QLCDNumber*>(ui->ext2V);
    auto ext2P = qobject_cast<QLCDNumber*>(ui->ext2P);
    assignPowerNodes(powerDistributionA, ext2V, ext2P, 15);

    auto ext3V = qobject_cast<QLCDNumber*>(ui->ext3V);
    auto ext3P = qobject_cast<QLCDNumber*>(ui->ext3P);
    assignPowerNodes(powerDistributionA, ext3V, ext3P, 15);

    auto condV = qobject_cast<QLCDNumber*>(ui->condV);
    auto condP = qobject_cast<QLCDNumber*>(ui->condP);
    assignPowerNodes(powerDistributionA, condV, condP, 20);

    auto lightV = qobject_cast<QLCDNumber*>(ui->lightV);
    auto lightP = qobject_cast<QLCDNumber*>(ui->lightP);
    assignPowerNodes(powerDistributionA, lightV, lightP, 20);

    auto capBank2V = qobject_cast<QLCDNumber*>(ui->capBank2V);
    auto capBank2P = qobject_cast<QLCDNumber*>(ui->capBank2P);
    assignPowerNodes(powerDistributionB, capBank2V, capBank2P, 8);

    auto line1V = qobject_cast<QLCDNumber*>(ui->line1V);
    auto line1P = qobject_cast<QLCDNumber*>(ui->line1P);
    assignPowerNodes(powerDistributionB, line1V, line1P, 12);

    auto line2V = qobject_cast<QLCDNumber*>(ui->line2V);
    auto line2P = qobject_cast<QLCDNumber*>(ui->line2P);
    assignPowerNodes(powerDistributionB, line2V, line2P, 10);

    auto carLineV = qobject_cast<QLCDNumber*>(ui->carLineV);
    auto carLineP = qobject_cast<QLCDNumber*>(ui->carLineP);
    assignPowerNodes(powerDistributionB, carLineV, carLineP, 30);

    auto vitals1V = qobject_cast<QLCDNumber*>(ui->vitals1V);
    auto vitals1P = qobject_cast<QLCDNumber*>(ui->vitals1P);
    assignPowerNodes(powerDistributionB, vitals1V, vitals1P, 15);


    auto vitals2V = qobject_cast<QLCDNumber*>(ui->vitals2V);
    auto vitals2P = qobject_cast<QLCDNumber*>(ui->vitals2P);
    assignPowerNodes(powerDistributionB, vitals2V, vitals2P, 15);


    auto vitals3V = qobject_cast<QLCDNumber*>(ui->vitals3V);
    auto vitals3P = qobject_cast<QLCDNumber*>(ui->vitals3P);
    assignPowerNodes(powerDistributionB, vitals3V, vitals3P, 10);

    drawBasicMicroScada();
    initializeTCPSocket();

    QTimer* stepTimer100ms = new QTimer(this);
    connect(stepTimer100ms, &QTimer::timeout, this, &MainWindow::simulationStep);
    stepTimer100ms->start(700);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::drawBasicMicroScada(){
    QString scadaDiagramSource = ":/symbols/resources/IEC_60617/IEC_60617_ScadaDiagramMain.svg";

    QWidget* parentContainer = qobject_cast<QWidget*>(ui->scadaWidget);

    QSvgWidget* svg = new QSvgWidget(scadaDiagramSource, parentContainer);
    svg->setGeometry(0, 0, parentContainer->width(), parentContainer->height());
}

void MainWindow::simulationStep(){
    for(auto& node : powerDistributionA){
        auto nVariation = QRandomGenerator::global()->bounded(-10, 15);
        node->setNodeVoltage(parentLineA->getVoltage() + nVariation);

        node->setNodeTotalPower(parentLineA->getTotalPower() * (node->powerLoad()/100 + QRandomGenerator::global()->bounded(0.05)));
    }

    for(auto& node : powerDistributionB){
        auto nVariation = QRandomGenerator::global()->bounded(-10, 15);
        node->setNodeVoltage(parentLineB->getVoltage() + nVariation);

        node->setNodeTotalPower(parentLineB->getTotalPower() * (node->powerLoad()/100 + QRandomGenerator::global()->bounded(0.05)));
    }
}

void MainWindow::assignPowerNodes(QList<PowerNode*>& nodeList, QLCDNumber* voltage, QLCDNumber* power, int percentage = 1){
    PowerNode* node = new PowerNode(voltage, power, percentage, this);
    nodeList.push_back(node);
}

void MainWindow::initializeTCPSocket(){
    TcpSocket = new QTcpSocket();
    TcpSocket->connectToHost(QHostAddress::LocalHost, 8080);

    if(TcpSocket->waitForConnected(30000)){
        qInfo()<<"Socket has successfully connected to the server";
    }
    else{
        qInfo()<<"Socket has failed to connect to the server";
        return;
    }

    connect(TcpSocket, &QTcpSocket::readyRead, [=](){
        QByteArray data = TcpSocket->readAll();
        QString rawString = QString::fromUtf8(data);

        QStringList information = rawString.split('\n');

        if(information[0] == "transformer1"){
            parentLineA->setNodeVoltage(information[1].toInt());
            parentLineA->setNodeTotalPower(information[2].toInt());
        }
        else if(information[0] == "transformer2"){
            parentLineB->setNodeVoltage(information[1].toInt());
            parentLineB->setNodeTotalPower(information[2].toInt());
        }
        else{
            qInfo()<<"Gargage information: " << rawString<<'\n';
        }
    });
}
