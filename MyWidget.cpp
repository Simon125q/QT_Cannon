#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    :QWidget(parent)
{
    setFixedSize(700, 340);

    // create child widget
    QPushButton *quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(50, 50, 300, 250);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    //qApp pointer is a global variable declared in the 
    //<QApplication> header file. It points to the application's 
    //unique QApplication instance.
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}