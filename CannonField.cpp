#include <QPainter>
#include <iostream>
#include "CannonField.h"

CannonField::CannonField(QWidget *parent)
    : QWidget(parent)
{
    currentAngle = 45;
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
}

int CannonField::angle() const
{
    return currentAngle;
}

void CannonField::setAngle(int angle)
{
    if (angle < 5)
        angle = 5;
    else if (angle > 70)
        angle = 70;
    if (angle == currentAngle)
        return;

    currentAngle = angle;
    update();
    emit angleChanged(currentAngle);
}

void CannonField::paintEvent(QPaintEvent * /* event */)
{
    
    QPainter painter(this);
    painter.drawText(200, 200, ("Angle = ") + QString::number(currentAngle));
}