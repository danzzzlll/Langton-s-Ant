#ifndef HEXAGON_H
#define HEXAGON_H

#include <QGraphicsPolygonItem>
#include <QVector>
#include <QPointF>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


/*!
 * \brief Класс гексагона
 *
 * Этот класс отвечает за отображение гексагона в пользовательском интерфейсе, а также за хранение, изменение и передачу его состояния.
 */
class Hexagon : public QGraphicsPolygonItem
{
public:
    /*!
     * \brief Создание нового гексагона
     * \param scene Указатель на сцену
     * \param x Координата x
     * \param y Координата y
     * \param size Размер гексагона
     *
     * Создаёт новый гексагон и помещает его в позицию x, y
     */
    Hexagon(QGraphicsScene* scene, qreal x, qreal y, qreal size);
    /*!
     * \brief Установка нового состояния
     * \param newState Новое значение
     */
    void setState(bool newState);
    /*!
     * \brief Текущее состояние
     * \return Текущее состояние гексагона
     */
    bool getState() const;
    /*!
     * \brief Построение шестиугольника
     * \param size Внешний радиус шестиугольника
     * \return новое графическое отображение гексагона выбранного размера
     *
     * Вспомогательная функция для конструктора, которая строит шестиугольник по точкам
     */
    static QVector<QPointF> createHexagon(qreal size);

private:
    bool state;
};

#endif // HEXAGON_H
