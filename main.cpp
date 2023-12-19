#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFont>
#include "MyWidget.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //app.setFont(QFont("Times", 18, QFont::Bold));
    // QWidget window;
    // window.resize(450, 320);
    // QPushButton quit("Quit! Right Now!", &window);
    // quit.setGeometry(75, 50, 300, 90);
    // quit.setFont(QFont("Times", 18, QFont::Bold));

    // // QObject::connect(*sender, signal, *receiver, method)
    // // Creates a connection of the given type from the signal 
    // // in the sender object to the method in the receiver object
    // // return true if connection succeded, false if not
    // QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));
    // // connect() call establishes a one-way connection between two Qt objects
    // // Every Qt object can have both signals (to send messages) and slots (to receive messages)
    // window.show();

    MyWidget widget;
    widget.show();
    return app.exec();
}