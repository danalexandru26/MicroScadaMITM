#ifndef SCALABLESVGWIDGET_H
#define SCALABLESVGWIDGET_H

#include <QSvgWidget>
#include <QObject>
#include <QSvgRenderer>
#include <QResizeEvent>

class scalableSvgWidget : public QSvgWidget
{
public:
    explicit scalableSvgWidget(const QString& file, QWidget* parent = nullptr)
        : QSvgWidget(file, parent) {}

protected:
};

#endif // SCALABLESVGWIDGET_H
