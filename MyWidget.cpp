#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QWidget>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QGridLayout>
#include "MyWidget.h"
#include "LCDRange.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    // setFixedSize(700, 340);

    // create child widget
    QPushButton *quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(50, 50, 700, 250);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    // QLCDNumber *lcd = new QLCDNumber(3);
    // lcd->setSegmentStyle(QLCDNumber::Filled);

    // QSlider *slider = new QSlider(Qt::Horizontal);
    // slider -> setRange(0, 999);
    // slider -> setValue(0);

    // QSpinBox *spinBox = new QSpinBox();
    // spinBox->setRange(0,999);
    // spinBox->setValue(0);

    QGridLayout *grid = new QGridLayout();
    LCDRange *previousRange = 0;

    for (int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 3; ++column)
        {
            LCDRange *lcdRange = new LCDRange;
            grid->addWidget(lcdRange, row, column);
            if (previousRange)
                connect(lcdRange, SIGNAL(valueChanged(int)), previousRange, SLOT(setValue(int)));
            previousRange = lcdRange;
        }
    }

    // qApp pointer is a global variable declared in the
    //<QApplication> header file. It points to the application's
    // unique QApplication instance.
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    // connect(spinBox, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    // manage the geometry of its child widgets
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    // layout->addWidget(lcd);
    // layout->addWidget(spinBox);
    layout->addLayout(grid);
    setLayout(layout);
}