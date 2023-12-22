#pragma once

#include <QWidget>

class QSlider;

class LCDRange : public QWidget
{
    // This macro must be included in all classes that contain signals and/or slots
    Q_OBJECT
private:
    QSlider *slider;
    
public:
    LCDRange(QWidget *parent = 0);
    int value() const;

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);
};

