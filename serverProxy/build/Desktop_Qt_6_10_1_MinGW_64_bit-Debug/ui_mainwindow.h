/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *labelT2V;
    QLabel *labelT2P;
    QLabel *labelT1V;
    QLabel *labelT1P;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(595, 416);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 200, 123, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 220, 117, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(140, 260, 123, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 280, 117, 16));
        labelT2V = new QLabel(centralwidget);
        labelT2V->setObjectName("labelT2V");
        labelT2V->setGeometry(QRect(280, 260, 123, 16));
        labelT2P = new QLabel(centralwidget);
        labelT2P->setObjectName("labelT2P");
        labelT2P->setGeometry(QRect(280, 280, 123, 16));
        labelT1V = new QLabel(centralwidget);
        labelT1V->setObjectName("labelT1V");
        labelT1V->setGeometry(QRect(280, 200, 123, 16));
        labelT1P = new QLabel(centralwidget);
        labelT1P->setObjectName("labelT1P");
        labelT1P->setGeometry(QRect(280, 220, 123, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(160, 30, 244, 47));
        label_5->setStyleSheet(QString::fromUtf8("color:red;\n"
"font: 26pt \"Segoe UI\";"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(180, 140, 189, 36));
        label_6->setStyleSheet(QString::fromUtf8("color:rgb(170, 170, 255);\n"
"font: 20pt \"Segoe UI\";"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Transformer 1 - Voltage", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Transformer 1 - Power", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Transformer 2 - Voltage", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Transformer 2 - Power", nullptr));
        labelT2V->setText(QString());
        labelT2P->setText(QString());
        labelT1V->setText(QString());
        labelT1P->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Malicious Proxy", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Received Values", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
