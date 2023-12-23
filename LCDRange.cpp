#include <QWidget>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>

#include "LCDRange.h"

LCDRange::LCDRange(QWidget *parent)
    :QWidget(parent)
{
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);

    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);

    // this mean that when someone (the program or the user) 
    // wants to give the LCDRange keyboard focus, the slider should take care of it
    setFocusProxy(slider);
}

int LCDRange::value() const
{
    return slider->value();
}

void LCDRange::setValue(int value)
{
    slider->setValue(value);
}

void LCDRange::setRange(int min, int max)
{
    if(min < 0 || max > 99 || min > max)
    {
        qWarning("Wrong range");
        return;
    }
    slider->setRange(min, max);
}