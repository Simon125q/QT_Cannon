#pragma once

#include <QWidget>
#include <stdlib.h>
#include <vector>


class CannonField : public QWidget
{
    Q_OBJECT
private:
    void paintShot(QPainter &painter);
    void paintCannon(QPainter &painter);
    void paintTarget(QPainter &painter);
    void paintTrajectory(QPainter &painter, std::vector<QRect> points);
    QRect cannonRect() const;
    QRect shotRect() const;
    QRect targetRect() const;
    std::vector<QRect> getTrajectory();

    int currentAngle;
    int currentForce;

    double timerCount;
    QTimer *autoShootTimer;
    float shootAngle;
    float shootForce;
    QPoint target;
    bool showTrajectory = false;

public:
    CannonField(QWidget *parent = 0);
    int angle() const;
    int force() const;

public slots:
    void setAngle(int angle);
    void setForce(int force);
    void shoot();
    void newTarget();
    void showBulletTrajctory();

private slots:
    void moveShot();

signals:
    void angleChanged(int newAngle);
    void forceChanged(int newForce);
    void targetHit();
    void targetMissed();

protected:
    void paintEvent(QPaintEvent *event);
};