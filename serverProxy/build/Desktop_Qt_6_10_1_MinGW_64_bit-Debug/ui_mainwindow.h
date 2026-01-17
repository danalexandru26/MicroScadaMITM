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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QGroupBox *groupBox;
    QTextEdit *labelT1P;
    QLabel *label;
    QTextEdit *labelT1V;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QTextEdit *labelT2P;
    QLabel *label_4;
    QLabel *label_3;
    QTextEdit *labelT2V;
    QGroupBox *groupBox_3;
    QTextEdit *labelT1P_Proxy;
    QTextEdit *labelT1V_Proxy;
    QLabel *label_9;
    QLabel *label_11;
    QGroupBox *groupBox_4;
    QTextEdit *labelT2P_Proxy;
    QLabel *label_10;
    QLabel *label_8;
    QTextEdit *labelT2V_Proxy;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(515, 998);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(160, 30, 244, 47));
        label_5->setStyleSheet(QString::fromUtf8("color:red;\n"
"font: 26pt \"Segoe UI\";"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(170, 110, 189, 36));
        label_6->setStyleSheet(QString::fromUtf8("color:rgb(82, 255, 154);\n"
"font: 20pt \"Segoe UI\";"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 500, 191, 36));
        label_7->setStyleSheet(QString::fromUtf8("color:rgb(255, 75, 87);\n"
"font: 20pt \"Segoe UI\";"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(120, 170, 291, 131));
        groupBox->setFlat(false);
        labelT1P = new QTextEdit(groupBox);
        labelT1P->setObjectName("labelT1P");
        labelT1P->setGeometry(QRect(160, 70, 111, 31));
        labelT1P->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        labelT1P->setFrameShape(QFrame::Shape::HLine);
        labelT1P->setFrameShadow(QFrame::Shadow::Sunken);
        labelT1P->setReadOnly(true);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 123, 16));
        labelT1V = new QTextEdit(groupBox);
        labelT1V->setObjectName("labelT1V");
        labelT1V->setGeometry(QRect(160, 20, 111, 31));
        labelT1V->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        labelT1V->setFrameShape(QFrame::Shape::HLine);
        labelT1V->setFrameShadow(QFrame::Shadow::Sunken);
        labelT1V->setReadOnly(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 117, 16));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(120, 330, 291, 131));
        groupBox_2->setFlat(false);
        labelT2P = new QTextEdit(groupBox_2);
        labelT2P->setObjectName("labelT2P");
        labelT2P->setGeometry(QRect(160, 80, 111, 31));
        labelT2P->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        labelT2P->setFrameShape(QFrame::Shape::HLine);
        labelT2P->setFrameShadow(QFrame::Shadow::Sunken);
        labelT2P->setReadOnly(true);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 90, 117, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 123, 16));
        labelT2V = new QTextEdit(groupBox_2);
        labelT2V->setObjectName("labelT2V");
        labelT2V->setGeometry(QRect(160, 20, 111, 31));
        labelT2V->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        labelT2V->setFrameShape(QFrame::Shape::HLine);
        labelT2V->setFrameShadow(QFrame::Shadow::Sunken);
        labelT2V->setReadOnly(true);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(120, 560, 291, 131));
        groupBox_3->setFlat(false);
        labelT1P_Proxy = new QTextEdit(groupBox_3);
        labelT1P_Proxy->setObjectName("labelT1P_Proxy");
        labelT1P_Proxy->setEnabled(true);
        labelT1P_Proxy->setGeometry(QRect(160, 70, 111, 31));
        labelT1P_Proxy->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        labelT1P_Proxy->setFrameShape(QFrame::Shape::HLine);
        labelT1P_Proxy->setFrameShadow(QFrame::Shadow::Sunken);
        labelT1P_Proxy->setReadOnly(false);
        labelT1P_Proxy->setAcceptRichText(false);
        labelT1V_Proxy = new QTextEdit(groupBox_3);
        labelT1V_Proxy->setObjectName("labelT1V_Proxy");
        labelT1V_Proxy->setEnabled(true);
        labelT1V_Proxy->setGeometry(QRect(160, 20, 111, 31));
        labelT1V_Proxy->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        labelT1V_Proxy->setFrameShape(QFrame::Shape::HLine);
        labelT1V_Proxy->setFrameShadow(QFrame::Shadow::Sunken);
        labelT1V_Proxy->setReadOnly(false);
        labelT1V_Proxy->setAcceptRichText(false);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 30, 123, 16));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 80, 117, 16));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(120, 710, 291, 131));
        groupBox_4->setFlat(false);
        labelT2P_Proxy = new QTextEdit(groupBox_4);
        labelT2P_Proxy->setObjectName("labelT2P_Proxy");
        labelT2P_Proxy->setEnabled(true);
        labelT2P_Proxy->setGeometry(QRect(170, 70, 111, 31));
        labelT2P_Proxy->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        labelT2P_Proxy->setFrameShape(QFrame::Shape::HLine);
        labelT2P_Proxy->setFrameShadow(QFrame::Shadow::Sunken);
        labelT2P_Proxy->setReadOnly(false);
        labelT2P_Proxy->setAcceptRichText(false);
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 30, 123, 16));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 80, 117, 16));
        labelT2V_Proxy = new QTextEdit(groupBox_4);
        labelT2V_Proxy->setObjectName("labelT2V_Proxy");
        labelT2V_Proxy->setEnabled(true);
        labelT2V_Proxy->setGeometry(QRect(170, 20, 111, 31));
        labelT2V_Proxy->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        labelT2V_Proxy->setFrameShape(QFrame::Shape::HLine);
        labelT2V_Proxy->setFrameShadow(QFrame::Shadow::Sunken);
        labelT2V_Proxy->setReadOnly(false);
        labelT2V_Proxy->setAcceptRichText(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 870, 131, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 920, 131, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Malicious Proxy", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Received Values", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Modified Values", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Transformer 1 - Voltage", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Transformer 1 - Power", nullptr));
        groupBox_2->setTitle(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Transformer 2 - Power", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Transformer 2 - Voltage", nullptr));
        groupBox_3->setTitle(QString());
        labelT1V_Proxy->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Transformer 1 - Voltage", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Transformer 1 - Power", nullptr));
        groupBox_4->setTitle(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Transformer 2 - Voltage", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Transformer 2 - Power", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Modify Data - T1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Modify Data - T2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
