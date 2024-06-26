#include "gamescene.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDir>
#include <QPainter>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene(parent), m_loopSpeed(int(1000.0f/60.0f)), m_loopTime(0.0f), m_deltaTime(0.0f),
    m_game(Game::Type::GosperGliderGun), m_1Pressed(false), m_2Pressed(false), m_3Pressed(false), m_4Pressed(false)
{
    setSceneRect(0,0, RESOLUTION.width(), RESOLUTION.height());
    setBackgroundBrush(Qt::black);
    connect(&m_timer, &QTimer::timeout, this, &GameScene::loop);
    m_timer.start(int(m_loopSpeed));
    m_elapsedTimer.start();
}

void GameScene::loop()
{
    m_deltaTime = m_elapsedTimer.elapsed();
    m_elapsedTimer.restart();

    m_loopTime += m_deltaTime;
    if( m_loopTime > m_loopSpeed)
    {
        m_loopTime -= m_loopSpeed;
        handlePlayerInput();
        m_game.update();
        clear();
        QGraphicsPixmapItem* pItem = new QGraphicsPixmapItem(QPixmap::fromImage(m_game.image().scaled(RESOLUTION.width(), RESOLUTION.height(), Qt::KeepAspectRatioByExpanding)));
        addItem(pItem);
    }
}

void GameScene::handlePlayerInput()
{
    if(m_1Pressed)
    {
        m_game.setType(Game::Type::Random);
        m_game.init();
        m_game.update();
        //m_game.print();
        m_1Pressed = false;
    }
    if(m_2Pressed)
    {
        m_game.setType(Game::Type::Pentomino);
        m_game.init();
        m_game.update();
        //m_game.print();
        m_2Pressed = false;
    }
    if(m_3Pressed)
    {
        m_game.setType(Game::Type::InfiniteGrowth);
        m_game.init();
        m_3Pressed = false;
    }
    if(m_4Pressed)
    {
        m_game.setType(Game::Type::GosperGliderGun);
        m_game.init();
        m_4Pressed = false;
    }
    if (m_5Pressed)
    {
        m_game.setType(Game::Type::Custom);
        m_game.init();
        m_5Pressed = false;
    }
}

void GameScene::renderScene()
{
    static int index = 0;
    QString fileName = QDir::currentPath() + QDir::separator() + "screen" + QString::number(index++) + ".png";
    QRect rect = sceneRect().toAlignedRect();
    QImage image(rect.size(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter painter(&image);
    render(&painter);
    image.save(fileName);
    qDebug() << "saved " << fileName;
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_1:
        {
            m_1Pressed = true;
        }
        break;
        case Qt::Key_2:
        {
            m_2Pressed = true;
        }
        break;
        case Qt::Key_3:
        {
            m_3Pressed = true;
        }
        break;
        case Qt::Key_4:
        {
            m_4Pressed = true;
        }
        break;
        case Qt::Key_5:
        {
            m_5Pressed = true;
        }
        break;
        case Qt::Key_P:
        {
            //renderScene();
        }
        break;
        }
    }

    QGraphicsScene::keyPressEvent(event);
}
