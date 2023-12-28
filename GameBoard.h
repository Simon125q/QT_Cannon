#pragma once

#include <QWidget>

class QLCDNumber;
class CannonField;

class GameBoard : public QWidget
{
    Q_OBJECT
private:
    QLCDNumber *hits;
    QLCDNumber *shotsLeft;
    CannonField *cannonField;

public:
    GameBoard(QWidget *Parent = 0);

protected slots:
    void fire();
    void hit();
    void missed();
    void newGame();
};