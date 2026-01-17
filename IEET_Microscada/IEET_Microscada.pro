QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += core widgets svg svgwidgets
QT += network

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    powernode.cpp \
    scalablesvgwidget.cpp

HEADERS += \
    mainwindow.h \
    powernode.h \
    scalablesvgwidget.h \


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/IEC_60617/IEC_60617.svg \
    resources/IEC_60617/IEC_60617_Breaker.svg \
    resources/IEC_60617/IEC_60617_Capacitor.svg \
    resources/IEC_60617/IEC_60617_ConnectionLine.svg \
    resources/IEC_60617/IEC_60617_CrossCon.svg \
    resources/IEC_60617/IEC_60617_DirectCon.svg \
    resources/IEC_60617/IEC_60617_DotCon.svg \
    resources/IEC_60617/IEC_60617_FullD.svg \
    resources/IEC_60617/IEC_60617_HollowD.svg \
    resources/IEC_60617/IEC_60617_LineSrc.svg \
    resources/IEC_60617/IEC_60617_Switch.svg \
    resources/IEC_60617/IEC_60617_TCon.svg \
    resources/IEC_60617/IEC_60617_Transformer.svg \
    resources/IEC_60617/IEC_60617_Transformer2.svg \
    resources/IEC_60617/IEC_60617_VerLineSrc.svg

RESOURCES += \
    Qt_resources.qrc
