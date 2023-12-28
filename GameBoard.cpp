#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QWidget>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QFrame>
#include <QLabel>
#include <QShortcut>
#include <QGridLayout>
#include "GameBoard.h"
#include "LCDRange.h"
#include "CannonField.h"

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
{

    // create child widget
    QPushButton *quit = new QPushButton(tr("Quit"), this);
    // quit->setGeometry(50, 50, 700, 250);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    QPushButton *shoot = new QPushButton(tr("Shoot"));
    shoot->setFont(QFont("Times", 18, QFont::Bold));

    QPushButton *showTrajctory = new QPushButton(tr("Trajectory"));
    showTrajctory->setFont(QFont("Times", 18, QFont::Bold));

    QPushButton *restart = new QPushButton(tr("NEW GAME"));
    restart->setFont(QFont("Times", 18, QFont::Bold));

    // qApp pointer is a global variable declared in the
    //<QApplication> header file. It points to the application's
    // unique QApplication instance.
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    LCDRange *angle = new LCDRange("Angle");
    angle->setRange(5, 70);

    LCDRange *force = new LCDRange("Force");
    force->setRange(0, 99);

    QFrame *cannonBox = new QFrame;
    cannonBox->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);

    cannonField = new CannonField;

    connect(angle, SIGNAL(valueChanged(int)), cannonField, SLOT(setAngle(int)));
    connect(cannonField, SIGNAL(angleChanged(int)), angle, SLOT(setValue(int)));
    connect(force, SIGNAL(valueChanged(int)), cannonField, SLOT(setForce(int)));
    connect(cannonField, SIGNAL(forceChanged(int)), force, SLOT(setValue(int)));
    connect(shoot, SIGNAL(clicked()), this, SLOT(fire()));
    connect(cannonField, SIGNAL(canShoot(bool)), shoot, SLOT(setEnabled(bool)));
    connect(cannonField, SIGNAL(targetHit()), cannonField, SLOT(newTarget()));
    connect(showTrajctory, SIGNAL(clicked()), cannonField, SLOT(showBulletTrajctory()));
    connect(cannonField, SIGNAL(targetHit()), this, SLOT(hit()));
    connect(cannonField, SIGNAL(targetMissed()), this, SLOT(missed()));
    connect(restart, SIGNAL(clicked()), this, SLOT(newGame()));

    hits = new QLCDNumber(2);
    hits->setSegmentStyle(QLCDNumber::Filled);
    QLabel *hitsLabel = new QLabel("HITS");

    shotsLeft = new QLCDNumber(2);
    shotsLeft->setSegmentStyle(QLCDNumber::Filled);
    QLabel *shotsLeftLabel = new QLabel("SHOTS LEFT");

    (void) new QShortcut(Qt::Key_Enter, this, SLOT(fire()));
    (void) new QShortcut(Qt::Key_Return, this, SLOT(fire()));
    (void) new QShortcut(Qt::CTRL + Qt::Key_Q, this, SLOT(close()));

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(shoot);
    topLayout->addWidget(showTrajctory);
    topLayout->addWidget(hits);
    topLayout->addWidget(hitsLabel);
    topLayout->addWidget(shotsLeft);
    topLayout->addWidget(shotsLeftLabel);
    topLayout->addStretch(1);
    topLayout->addWidget(restart);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(angle);
    leftLayout->addWidget(force);

    QVBoxLayout *cannonLayout = new QVBoxLayout;
    cannonLayout->addWidget(cannonField);
    cannonBox->setLayout(cannonLayout);

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addLayout(topLayout, 0, 1);
    gridLayout->addLayout(leftLayout, 1, 0);
    gridLayout->addWidget(cannonBox, 1, 1, 2, 1);

    // tells how to handle resize of a column relative to other elements
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);

    angle->setValue(60);
    force->setValue(25);

    // sets keyboard's focus on angle so that keyboard input will go to the LCDRange widget by default.
    angle->setFocus();

    newGame();

    // setFixedSize(700, 340);

    // QLCDNumber *lcd = new QLCDNumber(3);
    // lcd->setSegmentStyle(QLCDNumber::Filled);

    // QSlider *slider = new QSlider(Qt::Horizontal);
    // slider -> setRange(0, 999);
    // slider -> setValue(0);

    // QSpinBox *spinBox = new QSpinBox();
    // spinBox->setRange(0,999);
    // spinBox->setValue(0);

    // QGridLayout *grid = new QGridLayout();
    // LCDRange *previousRange = 0;

    // for (int row = 0; row < 3; ++row)
    // {
    //     for (int column = 0; column < 3; ++column)
    //     {
    //         LCDRange *lcdRange = new LCDRange;
    //         grid->addWidget(lcdRange, row, column);
    //         if (previousRange)
    //             connect(lcdRange, SIGNAL(valueChanged(int)), previousRange, SLOT(setValue(int)));
    //         previousRange = lcdRange;
    //     }
    // }

    // connect(spinBox, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    // manage the geometry of its child widgets
    // QVBoxLayout *layout = new QVBoxLayout;
    // layout->addWidget(quit);
    // // layout->addWidget(lcd);
    // // layout->addWidget(spinBox);
    // layout->addLayout(grid);
    // setLayout(layout);
}

void GameBoard::fire()
{
    if (cannonField->gameOver() || cannonField->isShooting())
        return;
    shotsLeft->display(shotsLeft->intValue() - 1);
    cannonField->shoot();
}

void GameBoard::hit()
{
    hits->display(hits->intValue() + 1);
    if (shotsLeft->intValue() == 0)
        cannonField->setGameOver();
    else
        cannonField->newTarget();
}

void GameBoard::missed()
{
    if (shotsLeft->intValue() == 0)
        cannonField->setGameOver();
}

void GameBoard::newGame()
{
    shotsLeft->display(15);
    hits->display(0);
    cannonField->restartGame();
    cannonField->newTarget();
}