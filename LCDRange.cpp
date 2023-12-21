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

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);

    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}