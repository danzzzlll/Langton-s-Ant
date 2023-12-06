#ifndef ANTITEM_H
#define ANTITEM_H

#include <QGraphicsPolygonItem>

//! Графическое отображение муравья
class AntItem : public QGraphicsPolygonItem {
public:
    //! Создание нового графического отображения муравья
    AntItem(QGraphicsScene* scene, int x, int y);
    /*!
    * \brief Обновление позиции муравья
    * \param x Новая координата x
    * \param y Новая координата y
    *
    * Обновление позиции муравья на гексагональном поле, где x и y - номер строки и столбца гексагона соответственно
    */
    void updatePosition(int x, int y);
};

#endif // ANTITEM_H
