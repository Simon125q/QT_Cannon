#include <QPainter>
#include <iostream>
#include "CannonField.h"

CannonField::CannonField(QWidget *parent)
    : QWidget(parent)
{
    currentAngle = 45;
    currentForce = 0;
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
    update(cannonRect());
    emit angleChanged(currentAngle);
}

int CannonField::force() const
{
    return currentForce;
}

void CannonField::setForce(int force)
{
    if (force < 0)
        force = 0;
    if (force == currentForce)
        return;

    currentForce = force;
    emit forceChanged(currentForce);
}

void CannonField::paintEvent(QPaintEvent * /* event */)
{

    QPainter painter(this);
    // pen is responsible for drawing edges
    painter.setPen(Qt::NoPen);
    // brush is responsible for filling shapes
    painter.setBrush(Qt::blue);

    painter.translate(0, rect().height());
    painter.drawPie(QRect(-35, -35, 70, 70), 0, 90 * 16);
    painter.rotate(-currentAngle);
    painter.drawRect(QRect(30, -5, 20, 10));
    // painter.drawText(200, 200, ("Angle = ") + QString::number(currentAngle));
}

QRect CannonField::cannonRect() const
{
    QRect result(0, 0, 50, 50);
    result.moveBottomLeft(rect().bottomLeft());
    return result;
}