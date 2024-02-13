#include "hexagon.h"
#include <cmath>
#include <QGraphicsScene>

QVector<QPointF> Hexagon::createHexagon(qreal size) {
    QVector<QPointF> points;
    for (int i = 0; i < 6; ++i) {
        qreal angle = 2 * M_PI / 6 * i;
        points << QPointF(size * cos(angle), size * sin(angle));
    }
    return points;
}

Hexagon::Hexagon(QGraphicsScene* scene, qreal x, qreal y, qreal size) : state(false) {
    setPolygon(QPolygonF(createHexagon(size)));
    setPos(x, y);
    scene->addItem(this);
}


void Hexagon::setState(bool newState) {
    state = newState;
    if (newState) {
        setBrush(QBrush(Qt::black));
    } else {
        setBrush(QBrush(Qt::white));
    }
}


bool Hexagon::getState() const {
    return state;
}


void Hexagon::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    this->setState(!(this->getState()));
    QGraphicsPolygonItem::mousePressEvent(event);
}
