#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QElapsedTimer>
#include "game.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);
    constexpr static const QSize RESOLUTION = QSize(960, 600);
signals:
private slots:
    void loop();
private:
    void handlePlayerInput();
    void renderScene();
    QTimer m_timer;
    QElapsedTimer m_elapsedTimer;
    const float m_loopSpeed;
    float m_loopTime, m_deltaTime;
    Game m_game;
    bool m_1Pressed, m_2Pressed, m_3Pressed, m_4Pressed, m_5Pressed;
    // QGraphicsScene interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // GAMESCENE_H
