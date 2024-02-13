#ifndef LANGTONANT_H
#define LANGTONANT_H

const int SizeX = 50;
const int SizeY = 30;


/*!
 * \brief Модель муравья Лэнгтона на гексагональной решётке
 */
class LangtonAnt {
public:
    /*!
     * \brief Создание нового муравья
     * \param x Начальная координата x
     * \param y Начальная координата y
     * \param direction Начальное направление от 0(вверх) до 5(влево-вверх) по часовой стрелке
     */
    LangtonAnt(int x, int y, int direction);
    /*!
     * \brief Движение вперёд
     *
     * Перемещение муравья на следующую гексагональную клетку в текущем направлении
     */
    void move();
    /*!
     * \brief Поворот налево
     *
     * Измененяет direction на следующее слева направление
     */
    void turnLeft();
    /*!
     * \brief Поворот направо
     *
     * Изменяет direction на следующее справа направление
     */
    void turnRight();

    /*!
     * \brief Координата x
     * \return текущее значение координаты x муравья
     */
    int getX() const;
    /*!
     * \brief Координата y
     * \return текущее значение координаты y муравья
     */
    int getY() const;
    /*!
     * \brief Текущее направление
     * \return текущее направление direction
     */
    int getDirection() const;
    /*!
     * \brief Установить новое состояние
     * \param posX Новая координата X
     * \param posY Новая координата Y
     * \param direction Новое направление от 0(вверх) до 5(влево-вверх) по часовой стрелке
     */
    void setState(int posX, int posY,int direction);

private:
    int x, y;
    int direction;
};

#endif // LANGTONANT_H
