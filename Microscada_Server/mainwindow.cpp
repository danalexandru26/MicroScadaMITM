#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectEvents();
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

void MainWindow::connectEvents(){
    connect(ui->sendDataTrans1, &QPushButton::clicked, this, &MainWindow::onClickSendDataTrans1);
    connect(ui->sendDataTrans2, &QPushButton::clicked, this, &MainWindow::onClickSendDataTrans2);
    connect(ui->dialTrans1, &QDial::valueChanged, this, &MainWindow::onChangeDialTrans1);
    connect(ui->dialTrans2, &QDial::valueChanged, this, &MainWindow::onChangeDialTrans2);
    connect(ui->dialTrans1_2, &QDial::valueChanged, this, &MainWindow::onChangeDialTrans1P);
    connect(ui->dialTrans2_2, &QDial::valueChanged, this, &MainWindow::onChangeDialTrans2P);
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
        QTcpSocket* client = TcpServer->nextPendingConnection();
        qInfo() << "Client connected";

        sslClient = new QSslSocket(this);
        sslClient->setSocketDescriptor(client->socketDescriptor());

        QByteArray cert;
        QByteArray key;

        QFile file_cert("D:/keys/server.cert");
        if(file_cert.open(QIODevice::ReadOnly)){
            cert = file_cert.readAll();
            file_cert.close();
        }

        QFile file_key("D:/keys/server.key");
        if(file_key.open(QIODevice::ReadOnly)){
            key = file_key.readAll();
            file_key.close();
        }
        QSslCertificate ssl_cert(cert);
        QSslKey ssl_key(key, QSsl::Rsa,QSsl::Pem,QSsl::PrivateKey);

        if(!ssl_cert.isNull()){
            qInfo()<<ssl_cert.subjectDisplayName();
        }

        if(!ssl_key.isNull()){
            qInfo()<<ssl_key.algorithm();
        }


        sslClient->setLocalCertificate(ssl_cert);
        sslClient->setPrivateKey(ssl_key);
        qInfo()<<"Handshake credentials set\n";

        sslClient->startServerEncryption();

        connect(sslClient, &QSslSocket::encrypted, this, [](){
            qInfo()<<"TLS Handshake";
        });


        connect(sslClient, &QSslSocket::readyRead, this, [=]() {
            //client sends no data
        });

        connect(sslClient, &QSslSocket::disconnected, this, [=]() {
            qInfo() << "Client disconnected";
            sslClient->deleteLater();
        });

        connect(sslClient, &QSslSocket::sslErrors, this, [](const QList<QSslError> &errors){
            for (const auto &err : errors) {
                qWarning() << "SSL Error:" << err.errorString();
            }
        });
    });
}

void MainWindow::onClickSendDataTrans1(){
    if(sslClient && sslClient->state() == QAbstractSocket::ConnectedState){
        QString voltage =  QString::number(ui->dialTrans1->value()) + '\n';
        QString power  = QString::number(ui->dialTrans1_2->value());

        if(sslClient && !sslClient->isEncrypted()){
            qInfo() << "TLS handshake not finished, cannot send yet";
            return;
        }
        qInfo()<<"Can send TLS encrypted data\n";
        QString messageTransformer1 = "transformer1\n" +  voltage + power;
        sslClient->write(messageTransformer1.toUtf8());
        sslClient->flush();
    }
    else{
        qInfo()<<"No client is connected\n";
    }
}

void MainWindow::onClickSendDataTrans2(){
    if(sslClient && sslClient->state() == QAbstractSocket::ConnectedState){
        QString voltage =  QString::number(ui->dialTrans2->value()) + '\n';
        QString power  = QString::number(ui->dialTrans2_2->value());

        QString messageTransformer1 = "transformer2\n" +  voltage + power;

        if(sslClient && !sslClient->isEncrypted()){
            qInfo() << "TLS handshake not finished, cannot send yet";
            return;
        }
        qInfo()<<"Can send TLS encrypted data\n";
        sslClient->write(messageTransformer1.toUtf8());
        sslClient->flush();
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

