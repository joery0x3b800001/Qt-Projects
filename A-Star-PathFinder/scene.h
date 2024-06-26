#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QSize>
#include <QTimer>
#include <QElapsedTimer>
#include "node.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

signals:


private:
    void OnCreateScene();
    void OnUpdateScene();
    bool solveAStar();
    void drawConnections(int nodeSize);
    void drawNodes(int nodeSize, int nodeBorder);
    void drawPath(int nodeSize);
    void renderScene();

    const QSize UNIT_SIZE   = QSize(5  , 5  );
    const QSize WINDOW_SIZE = QSize(135, 135);
    const QSize SCENE_SIZE  = QSize(UNIT_SIZE.width()*WINDOW_SIZE.width(), UNIT_SIZE.height()*WINDOW_SIZE.height());

    int nMapWidth = 15;
    int nMapHeight = 15;

    int m_mousePosX = 0;
    int m_mousePosY = 0;
    bool m_mouseReleased = false;
    bool m_shiftPressed = false;
    bool m_controlPressed = false;

    int FPS           = 60;
    float m_deltaTime = 0.0f;
    float m_loopTime  = 0.0f;
    const float m_loopSpeed = int(1000.0f/FPS);
    QTimer m_timer;
    QElapsedTimer m_elapsedTimer;

    Node* nodes = nullptr;
    Node* nodeStart = nullptr;
    Node* nodeEnd = nullptr;
private slots:
    void loop();

    // QGraphicsScene interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
