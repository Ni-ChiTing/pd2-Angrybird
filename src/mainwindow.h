#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <gameitem.h>
#include <QString>
#include <land.h>
#include "collision.h"
#include "bird.h"
#include "bar.h"
#include "enermy.h"
#include "yellowbird.h"
#include "backbird.h"
#include "twohitbird.h"
#include "ctime"
#include "gravitybird.h"
#include "rank.h"
#define PI 3.1415926
#define BIRDMAX 5
#define BIRD 0
#define BACKBIRD 1
#define YELLOWBIRD 2
#define TWOHITBIRD 3
#define GRAVITYBIRD 4
#include <QColor>
#include <QString>
#include "result.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void todelete();
     void keyPressEvent(QKeyEvent *event);

signals:
    // Signal for closing the game
    void quitGame();
    void gameover();
    void quit();
public slots:
    void showresult();
    void restart();
private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QList<bar*> itemlistb;
    QList<enermy *> itemListe;
    QTimer timer;
    QGraphicsPixmapItem *arrow;
    QGraphicsPixmapItem *hit;
    QGraphicsTextItem* qText,*qText2,*qText3;
    QPointF at,moveat;

    Bird *birdie;
    bar *wood5;
    bar *wood1;
    bar *wood2;
    bar *wood3;
    bar *wood4;
    bar *wood6;
    bar *rock1;
    bar *rock2;
    bar *rock3;
    bar *ice1;
    bar *ice2;
    int birdnumber;
    enermy *enermy1;
    enermy *enermy2;
    enermy *enermy3;
    enermy *enermy4;
    enermy *enermy5;
    collision *findhit;
    result *re;
    int score;

};

#endif // MAINWINDOW_H
