#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QVector>
#include <QPointF>
#include <QTimer>

#include "langtonant.h"
#include "antitem.h"
#include "hexagon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//! Главное окно пользовательского приложения
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*!
     * \brief Установка гексагональной решётки
     *
     * Итерационно создаёт решётку из гексагонов
     */
    void setupGrid();
    /*!
     * \brief Обновление позиции муравья Лэнгтона
     *
     * В соответствии с текущим положением муравья на гексагональной решётке выполняет его поворот, перемещение и изменение состояния гексагона.
     */
    void updateLangtonAnt();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    LangtonAnt ant;
    AntItem *antItem;
    QVector<QVector<Hexagon*>> grid; //< Хранение сетки гексагонов
    QTimer *timer;
};
#endif // MAINWINDOW_H
