#ifndef NODE_H
#define NODE_H
#include <QVector>

struct Node
{
    bool bObstacle = false;
    bool bVisited = false;
    float fGlobalGoal;
    float fLocalGoal;
    int x;
    int y;
    QVector<Node*> vecNeighbours;
    Node* parent;
};

#endif // NODE_H
