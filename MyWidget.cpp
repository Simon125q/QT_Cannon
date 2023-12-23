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
#include "CannonField.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{

    // create child widget
    QPushButton *quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(50, 50, 700, 250);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    // qApp pointer is a global variable declared in the
    //<QApplication> header file. It points to the application's
    // unique QApplication instance.
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    LCDRange *angle = new LCDRange;
    angle->setRange(5, 70);

    CannonField *cannonField = new CannonField;

    connect(angle, SIGNAL(valueChanged(int)), cannonField, SLOT(setAngle(int)));
    connect(cannonField, SIGNAL(angleChanged(int)), angle, SLOT(setValue(int)));

    QGridLayout *gridLayout = new QGridLayout;

    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(angle, 1, 0);
    gridLayout->addWidget(cannonField, 1, 1, 2, 1);

    // tells how to handle resize of a column relative to other elements
    gridLayout->setColumnStretch(1, 5);
    setLayout(gridLayout);

    angle->setValue(60);

    // sets keyboard's focus on angle so that keyboard input will go to the LCDRange widget by default.
    angle->setFocus();

    // setFixedSize(700, 340);

    // QLCDNumber *lcd = new QLCDNumber(3);
    // lcd->setSegmentStyle(QLCDNumber::Filled);

    // QSlider *slider = new QSlider(Qt::Horizontal);
    // slider -> setRange(0, 999);
    // slider -> setValue(0);

    // QSpinBox *spinBox = new QSpinBox();
    // spinBox->setRange(0,999);
    // spinBox->setValue(0);

    // QGridLayout *grid = new QGridLayout();
    // LCDRange *previousRange = 0;

    // for (int row = 0; row < 3; ++row)
    // {
    //     for (int column = 0; column < 3; ++column)
    //     {
    //         LCDRange *lcdRange = new LCDRange;
    //         grid->addWidget(lcdRange, row, column);
    //         if (previousRange)
    //             connect(lcdRange, SIGNAL(valueChanged(int)), previousRange, SLOT(setValue(int)));
    //         previousRange = lcdRange;
    //     }
    // }

    
    // connect(spinBox, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    // manage the geometry of its child widgets
    // QVBoxLayout *layout = new QVBoxLayout;
    // layout->addWidget(quit);
    // // layout->addWidget(lcd);
    // // layout->addWidget(spinBox);
    // layout->addLayout(grid);
    // setLayout(layout);
}