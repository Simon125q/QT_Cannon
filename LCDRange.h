#pragma once

#include <QWidget>

// forward declaring to speed up the compilation
class QLabel;
class QSlider;

class LCDRange : public QWidget
{
    // This macro must be included in all classes that contain signals and/or slots
    Q_OBJECT
private:
    QSlider *slider;
    QLabel *label;
    void init();

public:
    LCDRange(QWidget *parent = 0);
    LCDRange(const QString &text, QWidget *parent = 0);
    int value() const;
    QString text() const;

public slots:
    void setValue(int value);
    void setRange(int min, int max);
    void setText(const QString &text);

signals:
    void valueChanged(int newValue);
};
