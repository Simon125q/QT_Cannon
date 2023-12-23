#pragma once

#include <QWidget>

class CannonField : public QWidget
{
    Q_OBJECT
private:
    int currentAngle;

public:
    CannonField(QWidget *parent = 0);
    int angle() const;

public slots:
    void setAngle(int angle);

signals:
    void angleChanged(int newAngle);

protected:
    void paintEvent(QPaintEvent *event);
};