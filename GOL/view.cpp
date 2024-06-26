#include "view.h"
#include <QKeyEvent>
#include <QApplication>

View::View()
    : m_gameScene(new GameScene(this))
{
    setScene(m_gameScene);
    resize(GameScene::RESOLUTION.width(), GameScene::RESOLUTION.height());

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void View::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_Escape:
            QApplication::instance()->quit();
            break;
        }
    }

    QGraphicsView::keyPressEvent(event);
}
