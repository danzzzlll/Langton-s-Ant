#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QVector>
#include <QPointF>
#include <QTimer>
#include <QPushButton>
#include <QMessageBox>

#include "langtonant.h"
#include "antitem.h"
#include "hexagon.h"

#include <fstream>
#include <sstream>

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
    /*!
     * \brief Запуск/остановка симуляции
     *
     * Запускает и останавливает движение муравья по решётке.
     */
    void startPause();
    /*!
     * \brief Загрузить состояние из файла
     * \param grid Гексагональная решетка
     * \param ant Муравей Лэнгтона
     * \param filename Имя файла для открытия
     */
    void openMap0(QVector<QVector<Hexagon*>>& grid, LangtonAnt& ant, const std::string& filename);
    void openMap();
    /*!
     * \brief Сохранить состояние в файл
     * \param grid Гексагональная решетка
     * \param ant Муравей Лэнгтона
     * \param filename Имя файла для сохранения
     */
    void saveMap0(QVector<QVector<Hexagon*>>& grid, LangtonAnt& ant, const std::string& filename);
    void saveMap();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    LangtonAnt ant;
    AntItem *antItem;
    QVector<QVector<Hexagon*>> grid; //< Хранение сетки гексагонов
    QTimer *timer;
    bool isPaused = false;
};
#endif // MAINWINDOW_H
