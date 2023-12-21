#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QWidget>
#include <QVBoxLayout>
#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    :QWidget(parent)
{
    //setFixedSize(700, 340);

    // create child widget
    QPushButton *quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(50, 50, 700, 250);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    QLCDNumber *lcd = new QLCDNumber(3);
    lcd -> setSegmentStyle(QLCDNumber::Filled);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider -> setRange(0, 999);
    slider -> setValue(0);


    //qApp pointer is a global variable declared in the 
    //<QApplication> header file. It points to the application's 
    //unique QApplication instance.
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    //manage the geometry of its child widgets
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}