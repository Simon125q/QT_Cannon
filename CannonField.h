#pragma once

#include <QWidget>

class CannonField : public QWidget
{
    Q_OBJECT
private:
    QRect cannonRect() const;
    int currentAngle;
    int currentForce;

public:
    CannonField(QWidget *parent = 0);
    int angle() const;
    int force() const;

public slots:
    void setAngle(int angle);
    void setForce(int force);

signals:
    void angleChanged(int newAngle);
    void forceChanged(int newForce);

protected:
    void paintEvent(QPaintEvent *event);
};