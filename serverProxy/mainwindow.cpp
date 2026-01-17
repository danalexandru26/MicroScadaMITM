#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectEvents();

    proxyClientConnect();
    proxyServerConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::proxyClientConnect(){
    socketServer = new QSslSocket(this);

    QSslConfiguration conf = buildCertificates();

    socketServer->setSslConfiguration(conf);
    socketServer->connectToHostEncrypted("localhost", 9000);

    connect(socketServer, &QSslSocket::encrypted, this, [=]() {
        qInfo() << "TLS handshake complete!";
    });

    connect(socketServer, &QSslSocket::readyRead, this, [=]() {
        qInfo() << "TLS handshake complete - read available";
        QByteArray rawData = socketServer->readAll();
        QString data = QString::fromUtf8(rawData);
        displayValues(data);
        sslConnectionWrapper->write(rawData);
    });
}

void MainWindow::proxyServerConnect(){
    proxyServer = new QTcpServer(this);

    if(!proxyServer->listen(QHostAddress::LocalHost, 8080)){
        qInfo()<<"Proxy has failed to start\n";
    }
    qInfo()<<"Proxy has connected\n";

    connect(proxyServer, &QTcpServer::newConnection, this, [=](){
        QTcpSocket* connection = proxyServer->nextPendingConnection();

        sslConnectionWrapper = new QSslSocket(this);
        sslConnectionWrapper->setSocketDescriptor(connection->socketDescriptor());

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

        sslConnectionWrapper->setLocalCertificate(ssl_cert);
        sslConnectionWrapper->setPrivateKey(ssl_key);
        qInfo()<<"Handshake credentials set\n";

        sslConnectionWrapper->startServerEncryption();

        connect(sslConnectionWrapper, &QSslSocket::encrypted, this, [](){
            qInfo()<<"TLS Handshake";
        });

        connect(sslConnectionWrapper, &QSslSocket::disconnected, this, [=]() {
            qInfo() << "Client disconnected";
            sslConnectionWrapper->deleteLater();
        });
    });
}

QSslConfiguration MainWindow::buildCertificates(){
    QByteArray cert;
    QFile file_cert("D:/keys/server.cert");

    if(file_cert.open(QIODevice::ReadOnly)){
        cert = file_cert.readAll();
        file_cert.close();
    }
    else{
        qDebug() << file_cert.errorString();
    }

    QSslCertificate ssl_cert(cert);
    QList<QSslCertificate> listCA;
    listCA.append(ssl_cert);
    QSslConfiguration conf;
    conf.setCaCertificates(listCA);

    return conf;
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

    if(sslConnectionWrapper && sslConnectionWrapper->state() == QAbstractSocket::ConnectedState){
        if(transformer1Voltage.length() > 0 && transformer1Power.length() > 0){
            QString data = "transformer1\n" + transformer1Voltage + "\n" + transformer1Power+"\n";

            sslConnectionWrapper->write(data.toUtf8());
        }
    }
    else{
        qInfo()<<"Socket is not active!\n";
    }

    if(sslConnectionWrapper && sslConnectionWrapper->state() == QAbstractSocket::ConnectedState){
        if(transformer2Voltage.length() > 0 && transformer2Power.length() > 0){
            QString data = "transformer2\n" + transformer2Voltage + "\n" + transformer2Power +"\n";

            sslConnectionWrapper->write(data.toUtf8());
        }
    }
    else{
        qInfo()<<"Socket is not active!\n";
    }
}

void MainWindow::onPressAlterValuesT2(){
    QString transformer2Voltage = ui->labelT2V_Proxy->toPlainText();
    QString transformer2Power = ui->labelT2P_Proxy->toPlainText();

    if(sslConnectionWrapper && sslConnectionWrapper->state() == QAbstractSocket::ConnectedState){
        if(transformer2Voltage.length() > 0 && transformer2Power.length() > 0){
            QString data = "transformer2\n" + transformer2Voltage + "\n" + transformer2Power +"\n";

            sslConnectionWrapper->write(data.toUtf8());
        }
    }
    else{
        qInfo()<<"Socket is not active!\n";
    }
}

