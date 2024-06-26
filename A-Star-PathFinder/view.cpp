#include "view.h"
#include <QKeyEvent>
#include <QApplication>

View::View()
    : m_scene(new Scene(this))
{
    setScene(m_scene);
    resize(m_scene->sceneRect().width(), m_scene->sceneRect().height());

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void View::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        switch (event->key()) {
        case Qt::Key_Escape:
        {
            QApplication::quit();
        }
        break;
        }
    }
    QGraphicsView::keyPressEvent(event);
}
