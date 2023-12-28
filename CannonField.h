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
    void paintBarrier(QPainter &painter);
    QRect cannonRect() const;
    QRect shotRect() const;
    QRect targetRect() const;
    QRect barrierRect() const;
    std::vector<QRect> getTrajectory();

    bool barrelHit(const QPoint &pos) const;

    int currentAngle;
    int currentForce;

    double timerCount;
    QTimer *autoShootTimer;
    float shootAngle;
    float shootForce;
    QPoint target;
    bool showTrajectory;
    bool gameEnded;
    bool barrelPressed;

public:
    CannonField(QWidget *parent = 0);
    int angle() const;
    int force() const;
    bool gameOver() const;
    bool isShooting() const;

public slots:
    void setAngle(int angle);
    void setForce(int force);
    void shoot();
    void newTarget();
    void showBulletTrajctory();
    void setGameOver();
    void restartGame();

private slots:
    void moveShot();

signals:
    void angleChanged(int newAngle);
    void forceChanged(int newForce);
    void targetHit();
    void targetMissed();
    void canShoot(bool can);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};