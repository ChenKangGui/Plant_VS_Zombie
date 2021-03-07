#include "mainwindow.h"
#include <time.h>
#include "shovel.h"
#include "button.h"
#include "map.h"
#include "mower.h"
#include <QTime>
#include <QMediaPlayer>
#include "zombie.h"
#include "basiczombie.h"
#include "bucketzombie.h"
#include "conezombie.h"
#include "footballzombie.h"
#include "screenzombie.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("植物大战僵尸");
    setFixedSize(900, 600);
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("d:/gui/PlantWar/Dave.mp3"));
    player->play();

    timer = new QTimer();

    scene = new QGraphicsScene(this);
    scene->setSceneRect(150, 0, 900, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);//禁用下标

    Shop *shop = new Shop;
    shop->setPos(520, 45);
    scene->addItem(shop);

    Shovel *shovel = new Shovel();
    shovel->setPos(830, 40);
    scene->addItem(shovel);

    Button *button = new Button(sound, timer);
    button->setPos(970, 20);
    scene->addItem(button);

    Map *map = new Map;
    map->setPos(618, 326);
    scene->addItem(map);

    for(int i=0; i<5; i++)
    {
        Mower *mower = new Mower();
        mower->setPos(210, 130+98*i);
        scene->addItem(mower);
    }



    view = new QGraphicsView(scene, this);
    view->resize(902, 602);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/res/Background.jpg"));
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->show();

    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::addZombie);
    connect(timer, &QTimer::timeout, this, &MainWindow::check);

    timer->start(33);

}



MainWindow::~MainWindow()
{

}

void MainWindow::addZombie()
{
    static int low = 4;
    static int high = 8;
    static int maxtime = 5 * 1000 / 30;
    static int time = maxtime;
    static int counter = 0;
    if(++counter >= time)
    {
        if(++low > high)
        {
            maxtime /= 1.3;
            high *= 2;
        }
        counter = 0;
        time = qrand() % (2*maxtime / 3) + maxtime / 3;
        int type = qrand() % 50;
        int i = qrand() % 5;
        Zombie *zombie;
        if(type < 10)
        {
            zombie = new BasicZombie();
        }
        else if(type < 20)
        {
            zombie = new BucketZombie();
        }
        else if(type < 30)
        {
            zombie = new ConeZombie();
        }
        else if(type < 40)
        {
            zombie = new FootballZombie();
        }
        else if(type < 50)
        {
            zombie = new ScreenZombie();
        }

        zombie->setPos(1028, 130+98 *i);
        scene->addItem(zombie);
    }

}

void MainWindow::check()
{
    static int time = 1000 / 33;
    static int counter = 0;
    if(++counter >= time)
    {
        counter = 0;
        const QList<QGraphicsItem *> items = scene->items();
        foreach (QGraphicsItem *item, items)
        {
            if(item->type() == Zombie::Type && item->x() < 200)
            {
                scene->addPixmap(QPixmap(":/res/ZombiesWon.png"))->setPos(336, 92);
                scene->advance();
                timer->stop();
                return ;
            }
        }
    }
}


