#pragma once

#include <QWidget>


class CannonField : public QWidget
{
    Q_OBJECT
private:
    void paintShot(QPainter &painter);
    void paintCannon(QPainter &painter);
    QRect cannonRect() const;
    QRect shotRect() const;

    int currentAngle;
    int currentForce;

    int timerCount;
    QTimer *autoShootTimer;
    float shootAngle;
    float shootForce;

public:
    CannonField(QWidget *parent = 0);
    int angle() const;
    int force() const;

public slots:
    void setAngle(int angle);
    void setForce(int force);
    void shoot();

private slots:
    void moveShot();

signals:
    void angleChanged(int newAngle);
    void forceChanged(int newForce);

protected:
    void paintEvent(QPaintEvent *event);
};