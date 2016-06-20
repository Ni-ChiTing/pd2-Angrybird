#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),birdnumber(BIRDMAX),score(0)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
       re=new result(this);
    connect(this,SIGNAL(gameover()),this,SLOT(showresult()));
    connect(re,SIGNAL(exit()),this,SLOT(QUITSLOT()));
    connect(re,SIGNAL(restart()),this,SLOT(restart()));
    connect(re,SIGNAL(ok()),this,SLOT(QUITSLOT()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    srand(time(NULL));
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    scene->addPixmap(QPixmap(":/image/back1.png").scaled(1280,610));
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -8.0f));
    // Setting Size
    qText=new  QGraphicsTextItem;
    qText->setPlainText(QString::number(score));

    qText->setDefaultTextColor(QColor(0, 244, 125, 127));
    qText->setScale(3);
    qText->setFont(QFont("Fixedsys"));
     qText->setPos( 1100, 25 );
      scene->addItem(qText);

      qText2=new  QGraphicsTextItem;
      qText2->setPlainText(QString::number(birdnumber));
      qText2->setDefaultTextColor(QColor(255, 231, 0, 127));
      qText2->setScale(3);
      qText2->setFont(QFont("Fixedsys"));
       qText2->setPos( 200, 25 );
        scene->addItem(qText2);
        qText3=new  QGraphicsTextItem;
        qText3->setPlainText("Birds: ");
        qText3->setDefaultTextColor(QColor(0, 55, 125, 255));
        qText3->setScale(3);
        qText3->setFont(QFont("Fixedsys"));
         qText3->setPos( 20, 25 );
          scene->addItem(qText3);
    findhit=new collision;
    world->SetContactListener(findhit);
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16.0,1.5,32,3.000000,QPixmap(":/image/ground.png").scaled(1280,120),world,scene));
    hit=new QGraphicsPixmapItem;
    hit->setPixmap(QPixmap(":/image/throw.png").scaled(80,120, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    hit->setPos(100,480);
    scene->addItem(hit);
    int a;
    a=(rand()%5);
    qDebug()<<"rand"<<a;
 if(a==BIRD)
birdie = new Bird(3.3f,5.5f,0.5f,&timer,QPixmap(":/bird.png").scaled(40,40),world,scene);
    if(a==BACKBIRD)
        birdie = new backbird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/backbird.png").scaled(40,40),world,scene);
    if(a==YELLOWBIRD)
   birdie = new yellowbird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/yellowbird.png").scaled(40,40),world,scene);
    if(a==TWOHITBIRD)
   birdie = new twohitbird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/twohitbird.png").scaled(40,40),world,scene);
    if(a==GRAVITYBIRD)
   birdie = new gravitybird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/gravitybird.png").scaled(40,40),world,scene);

    // Setting the Velocity
    // Create bird (You can edit here)
    arrow=new QGraphicsPixmapItem;
    arrow->setPixmap(QPixmap(":/image/arrow.png").scaled(240, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    arrow->setTransformOriginPoint(arrow->pixmap().width()/2, arrow->pixmap().height()/2);//設置旋轉點
                  //qDebug()<<arrow->pixmap().width()<<arrow->pixmap().height();
    arrow->setPos(80,450);//設置圖片位置
                arrow->setTransformationMode(Qt::SmoothTransformation);
                scene->addItem(arrow);
                 arrow->setVisible(false);
    birdie->setLinearVelocity(b2Vec2(0,0));
    // Timer
    wood5=new bar(20.0f,4.5000f,0.5f,3.000000f,&timer,QPixmap(":/image/wood.png").scaled(20,120),world,scene,12,1);
    wood1=new bar(23.5f,4.5000f,0.5f,3.00000f,&timer,QPixmap(":/image/wood.png").scaled(20,120),world,scene,12,1);
    wood2=new bar(21.75f,6.25f,4.0f,0.5f,&timer,QPixmap(":/image/woodt.png").scaled(160,20),world,scene,12,2);
    wood6=new bar(23.75f,4.5000f,0.5f,3.000000f,&timer,QPixmap(":/image/wood.png").scaled(20,120),world,scene,12,1);
    wood3=new bar(27.25f,4.5000f,0.5f,3.00000f,&timer,QPixmap(":/image/wood.png").scaled(20,120),world,scene,12,1);
    wood4=new bar(25.75f,6.25f,4.0f,0.5f,&timer,QPixmap(":/image/woodt.png").scaled(160,20),world,scene,12,2);
    rock1=new bar(19.75f,4.5000f,0.5f,3.000000f,&timer,QPixmap(":/image/rock.png").scaled(20,120),world,scene,25,3);
    rock2=new bar(27.25f,4.5000f,0.5f,3.000000f,&timer,QPixmap(":/image/rock.png").scaled(20,120),world,scene,25,3);
    rock3=new bar(23.75f,6.75f,4.0f,0.5f,&timer,QPixmap(":/image/rockt.png").scaled(160,20),world,scene,12,4);
    ice1=new bar(23.75f,7.25f,4.0f,0.5f,&timer,QPixmap(":/image/icet.png").scaled(160,20),world,scene,8,6);
    ice2=new bar(23.75f,7.75f,4.0f,0.5f,&timer,QPixmap(":/image/icet.png").scaled(160,20),world,scene,8,6);
    enermy1=new enermy(29.0f,3.5f,0.5f,&timer,QPixmap(":/image/pig.png").scaled(40,40),world,scene,2,1);
    enermy2=new enermy(22.0f,3.5f,0.7f,&timer,QPixmap(":/image/pigbn.png").scaled(56,56),world,scene,5,2);
    enermy3=new enermy(25.5f,3.5f,0.7f,&timer,QPixmap(":/image/pigbo.png").scaled(56,56),world,scene,8,3);
    enermy4=new enermy(23.75f,8.8f,0.7f,&timer,QPixmap(":/image/pigbk.png").scaled(56,56),world,scene,8,4);
    enermy5=new enermy(18.0f,3.5f,0.7f,&timer,QPixmap(":/image/pigbm.png").scaled(56,56),world,scene,15,5);
    itemlistb.push_back(wood5);
    itemlistb.push_back(wood1);
    itemlistb.push_back(wood2);
    itemlistb.push_back(wood3);
    itemlistb.push_back(wood4);
    itemlistb.push_back(wood6);
    itemlistb.push_back(rock1);
    itemlistb.push_back(rock2);
    itemlistb.push_back(rock3);
    itemlistb.push_back(ice1);
    itemlistb.push_back(ice2);
    itemListe.push_back(enermy1);
    itemListe.push_back(enermy2);
    itemListe.push_back(enermy3);
    itemListe.push_back(enermy4);
    itemListe.push_back(enermy5);
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    if(event->type() == QEvent::MouseButtonPress&&birdnumber>0&&birdie->unfly)
    {
        arrow->setVisible(true);
        at=mouseEvent->pos();
    }
    if(event->type() == QEvent::MouseMove&&birdnumber>0&&birdie->unfly)
    {
        moveat=static_cast<QMouseEvent*>(event)->pos();
                arrow->resetTransform();//回復原本形狀
                arrow->setPos(250-120,448-50);
                arrow->setRotation(qAtan2((moveat.y()-at.y()),(moveat.x()-at.x()))*180/PI);
                arrow->setScale(qSqrt(qPow(moveat.y()-at.y(), 2) + qPow(moveat.x()-at.x(), 2))/900+0.25);
    }
    if(event->type() == QEvent::MouseButtonRelease&&birdnumber>0&&birdie->unfly)
    {
               arrow->setVisible(false);
               birdie->setLinearVelocity(b2Vec2((moveat.x()-at.x())/50,-(moveat.y()-at.y())/50));
               birdie->GameItem::setgravity();
               birdie->unfly=false;

    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::todelete()
{
    for(int i=0;i<itemlistb.length();i++)
    {
       if(itemlistb.at(i)&&itemlistb.at(i)->ifdelete)
       {
           score=score+500;
        delete itemlistb.at(i);
           itemlistb.removeAt(i);
           // qDebug()<<itemlistb;
       }
    }
    for(int i=0;i<itemListe.length();i++)
    {

        if((itemListe.at(i)&&itemListe.at(i)->ifdelete)||itemListe.at(i)->getX()>33||itemListe.at(i)->getY()<-5)
       {
          score=score+ itemListe.at(i)->gettype()*1000;
        delete itemListe.at(i);
           itemListe.removeAt(i);

       }
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space&&birdie&&(!birdie->ifkey)&&(!birdie->unfly)&&birdie)
    {
        birdie->fuction();
        //qDebug()<<"key";
    }

}

void MainWindow::showresult()
{

    re->setscore(score);
    re->show();

}

void MainWindow::restart()
{
    birdnumber=BIRDMAX;
    for (int i=0;i<itemlistb.length();i++)
    {

        delete itemlistb.at(i);
    }
    for (int i=0;i<itemListe.length();i++)
    {
       delete itemListe.at(i);
    }
    itemlistb.clear();
    itemListe.clear();
    int a;
    a=(rand()%5);
    qDebug()<<"rand"<<a;
 if(a==BIRD)
birdie = new Bird(3.3f,5.5f,0.5f,&timer,QPixmap(":/bird.png").scaled(40,40),world,scene);
    if(a==BACKBIRD)
        birdie = new backbird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/backbird.png").scaled(40,40),world,scene);
    if(a==YELLOWBIRD)
   birdie = new yellowbird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/yellowbird.png").scaled(40,40),world,scene);
    if(a==TWOHITBIRD)
   birdie = new twohitbird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/twohitbird.png").scaled(40,40),world,scene);
    if(a==GRAVITYBIRD)
   birdie = new gravitybird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/gravitybird.png").scaled(40,40),world,scene);
    wood5=new bar(20.0f,4.5000f,0.5f,3.000000f,&timer,QPixmap(":/image/wood.png").scaled(20,120),world,scene,12,1);
    wood1=new bar(23.5f,4.5000f,0.5f,3.00000f,&timer,QPixmap(":/image/wood.png").scaled(20,120),world,scene,12,1);
    wood2=new bar(21.75f,6.25f,4.0f,0.5f,&timer,QPixmap(":/image/woodt.png").scaled(160,20),world,scene,12,2);
    wood6=new bar(23.75f,4.5000f,0.5f,3.000000f,&timer,QPixmap(":/image/wood.png").scaled(20,120),world,scene,12,1);
    wood3=new bar(27.25f,4.5000f,0.5f,3.00000f,&timer,QPixmap(":/image/wood.png").scaled(20,120),world,scene,12,1);
    wood4=new bar(25.75f,6.25f,4.0f,0.5f,&timer,QPixmap(":/image/woodt.png").scaled(160,20),world,scene,12,2);
    rock1=new bar(19.75f,4.5000f,0.5f,3.000000f,&timer,QPixmap(":/image/rock.png").scaled(20,120),world,scene,25,3);
    rock2=new bar(27.25f,4.5000f,0.5f,3.000000f,&timer,QPixmap(":/image/rock.png").scaled(20,120),world,scene,25,3);
    rock3=new bar(23.75f,6.75f,4.0f,0.5f,&timer,QPixmap(":/image/rockt.png").scaled(160,20),world,scene,12,4);
    ice1=new bar(23.75f,7.25f,4.0f,0.5f,&timer,QPixmap(":/image/icet.png").scaled(160,20),world,scene,8,6);
    ice2=new bar(23.75f,7.75f,4.0f,0.5f,&timer,QPixmap(":/image/icet.png").scaled(160,20),world,scene,8,6);
    enermy1=new enermy(29.0f,3.5f,0.5f,&timer,QPixmap(":/image/pig.png").scaled(40,40),world,scene,2,1);
    enermy2=new enermy(22.0f,3.5f,0.7f,&timer,QPixmap(":/image/pigbn.png").scaled(56,56),world,scene,5,2);
    enermy3=new enermy(25.5f,3.5f,0.7f,&timer,QPixmap(":/image/pigbo.png").scaled(56,56),world,scene,8,3);
    enermy4=new enermy(23.75f,8.8f,0.7f,&timer,QPixmap(":/image/pigbk.png").scaled(56,56),world,scene,8,4);
    enermy5=new enermy(18.0f,3.5f,0.7f,&timer,QPixmap(":/image/pigbm.png").scaled(56,56),world,scene,15,5);
    itemlistb.push_back(wood5);
    itemlistb.push_back(wood1);
    itemlistb.push_back(wood2);
    itemlistb.push_back(wood3);
    itemlistb.push_back(wood4);
    itemlistb.push_back(wood6);
    itemlistb.push_back(rock1);
    itemlistb.push_back(rock2);
    itemlistb.push_back(rock3);
    itemlistb.push_back(ice1);
    itemlistb.push_back(ice2);
    itemListe.push_back(enermy1);
    itemListe.push_back(enermy2);
    itemListe.push_back(enermy3);
    itemListe.push_back(enermy4);
    itemListe.push_back(enermy5);
    score=0;
    timer.start(100/6);

}

void MainWindow::tick()
{

    if(itemListe.length()==0)
    {

            if(birdnumber>=0)
            {
                score=birdnumber*10000;
                birdnumber=0;
                delete birdie;
                birdie=NULL;
            }

                timer.stop();
    emit gameover();
    }
    if (birdie)
    {

    if(birdie->ifdelete||(birdie->getvx()==0&&birdie->getvy()==0&&(!birdie->unfly))||birdie->getX()>35||birdie->getY()>20||birdie->getX()<-5||birdie->getY()<-5)
    {
        //birdie->deletebody(world);
        birdie->setdead();
        int a;
        birdnumber=birdnumber-1;
        delete birdie;
        if(birdnumber==0)
        {qDebug()<<"here";
    timer.stop();
            emit gameover();
            birdie=NULL;
        }
/*#define BIRD 0
#define BACKBIRD 1
#define YELLOWBIRD 2
#define TWOHITBIRD 3
#define GRAVITYBIRD 4 */
        if(birdnumber>0)
        {
            a=(rand()%5);
            qDebug()<<"rand"<<a;
         if(a==BIRD)
        birdie = new Bird(3.3f,5.5f,0.5f,&timer,QPixmap(":/bird.png").scaled(40,40),world,scene);
            if(a==BACKBIRD)
                birdie = new backbird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/backbird.png").scaled(40,40),world,scene);
            if(a==YELLOWBIRD)
           birdie = new yellowbird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/yellowbird.png").scaled(40,40),world,scene);
            if(a==TWOHITBIRD)
           birdie = new twohitbird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/twohitbird.png").scaled(40,40),world,scene);
            if(a==GRAVITYBIRD)
           birdie = new gravitybird(3.3f,5.5f,0.5f,&timer,QPixmap(":/image/gravitybird.png").scaled(40,40),world,scene);

        //qDebug()<<birdnumber;
        }

    }
  qText2->setPlainText(QString::number(birdnumber));
     qText->setPlainText(QString::number(score));
     todelete();
     world->Step(1.0/60.0,6,2);
    scene->update();
}
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
    emit quit();
    this->close();
}
