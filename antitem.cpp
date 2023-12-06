#include "antitem.h"
#include "hexagon.h"
#include <cmath>
#include <QGraphicsScene>

AntItem::AntItem(QGraphicsScene* scene, int x, int y) {
    qreal antSize = 5;

    QPolygonF hexagonShape = Hexagon::createHexagon(antSize);
    setBrush(QBrush(Qt::red));
    setPolygon(hexagonShape);

    scene->addItem(this);
}


void AntItem::updatePosition(int gridX, int gridY) {
    qreal s = 20.0;

    qreal width = s * 3 / 2;
    qreal height = sqrt(3) * s / 2;

    qreal x = gridX * width;
    qreal y = gridY * height * 2;
    if (gridX % 2 == 1) {
        y += height;
    }

    setPos(x, y);
}
