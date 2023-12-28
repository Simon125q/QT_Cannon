#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QTime>
#include <QRegion>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "CannonField.h"
#include <stdlib.h>
#include <vector>

CannonField::CannonField(QWidget *parent)
    : QWidget(parent)
{
    currentAngle = 45;
    currentForce = 0;
    timerCount = 0;
    autoShootTimer = new QTimer(this);
    connect(autoShootTimer, SIGNAL(timeout()), this, SLOT(moveShot()));
    shootAngle = 0;
    shootForce = 0;
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
    newTarget();
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

void CannonField::shoot()
{
    if (autoShootTimer->isActive())
        return;
    timerCount = 0;
    shootAngle = currentAngle;
    shootForce = currentForce;
    autoShootTimer->start(3);
    showTrajectory = false;
    update(cannonRect());
}

void CannonField::newTarget()
{
    static bool firtsTime = true;
    if (firtsTime)
    {
        firtsTime = false;
        QTime midnight(0, 0, 0);
        srand(midnight.secsTo(QTime::currentTime()));
    }
    target = QPoint(200 + rand() % 190, 10 + rand() % 255);
    update();
}

const QRect barrelRect(30, -5, 20, 10);

std::vector<QRect> CannonField::getTrajectory()
{
    std::vector<QRect> result;
    double x = 0, y = 0;
    double simulatedTime = 0;
    while (!(x > width() && height() - 1 - y > height()))
    {
        simulatedTime += 10;
        double gravity = 4;
        double time = simulatedTime / 20;
        double velocity = currentForce;
        double radians = currentAngle * 3.14159 / 180;
        double velx = velocity * cos(radians);
        double vely = velocity * sin(radians);
        double x0 = (barrelRect.right() + 5) * cos(radians);
        double y0 = (barrelRect.right() + 5) * sin(radians);
        x = x0 + velx * time;
        y = y0 + vely * time - 0.5 * gravity * time * time;
        QRect rect(0, 0, 6, 6);
        rect.moveCenter(QPoint(qRound(x), height() - 1 - qRound(y)));
        result.push_back(rect);
    }

    
    return result;
}

void CannonField::showBulletTrajctory()
{
    showTrajectory = !showTrajectory;
    update();
}

void CannonField::moveShot()
{
    QRegion region = shotRect();
    timerCount += 0.8;

    QRect shotR = shotRect();
    if (shotR.intersects(targetRect()))
    {
        autoShootTimer->stop();
        emit targetHit();
    }
    else if (shotR.x() > width() || shotR.y() > height())
    {
        autoShootTimer->stop();
        update(cannonRect());
        emit targetMissed();
    }
    else
        region = region.united(shotR);
    update(region);
}

void CannonField::paintEvent(QPaintEvent * /* event */)
{

    QPainter painter(this);

    paintCannon(painter);
    if (autoShootTimer->isActive())
        paintShot(painter);
    paintTarget(painter);
    if (showTrajectory)
    {
        paintTrajectory(painter, getTrajectory());
        update();
    }
}

void CannonField::paintCannon(QPainter &painter)
{
    // pen is responsible for drawing edges
    painter.setPen(Qt::NoPen);
    // brush is responsible for filling shapes
    if (autoShootTimer->isActive())
        painter.setBrush(Qt::green);
    else
        painter.setBrush(Qt::blue);

    painter.save();
    painter.translate(0, height());
    painter.drawPie(QRect(-35, -35, 70, 70), 0, 90 * 16);
    painter.rotate(-currentAngle);
    painter.drawRect(barrelRect);
    painter.restore();
    // painter.drawText(200, 200, ("Angle = ") + QString::number(currentAngle));
}

void CannonField::paintShot(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.drawEllipse(shotRect());
}

void CannonField::paintTarget(QPainter &painter)
{
    painter.setPen(Qt::black);
    painter.setBrush(Qt::red);
    painter.drawRect(targetRect());
}

void CannonField::paintTrajectory(QPainter &painter, std::vector<QRect> points)
{
    painter.setPen(Qt::gray);
    painter.setBrush(Qt::NoBrush);
    for (auto p = points.begin(); p != points.end(); p++)
    {
        painter.drawEllipse(*p);
    }
}

QRect CannonField::cannonRect() const
{
    QRect result(0, 0, 50, 50);
    result.moveBottomLeft(rect().bottomLeft());
    return result;
}

QRect CannonField::shotRect() const
{
    const double gravity = 4;
    double time = timerCount / 20;
    double velocity = shootForce;
    double radians = shootAngle * 3.14159 / 180;
    double velx = velocity * cos(radians);
    double vely = velocity * sin(radians);
    double x0 = (barrelRect.right() + 5) * cos(radians);
    double y0 = (barrelRect.right() + 5) * sin(radians);
    double x = x0 + velx * time;
    double y = y0 + vely * time - 0.5 * gravity * time * time;

    QRect result(0, 0, 6, 6);
    result.moveCenter(QPoint(qRound(x), height() - 1 - qRound(y)));
    return result;
}

QRect CannonField::targetRect() const
{
    QRect result(0, 0, 20, 10);
    result.moveCenter(QPoint(target.x(), height() - 1 - target.y()));
    return result;
}