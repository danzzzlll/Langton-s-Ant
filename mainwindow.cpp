#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "antitem.h"
#include "hexagon.h"
#include "langtonant.h"
#include <cmath>
#include <QTimer>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ant(0, 0, 0)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    grid = *new QVector<QVector<Hexagon*>>(SizeY,QVector<Hexagon*>(SizeX));

    setupGrid();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLangtonAnt);
    timer->start(100);

    this->setCentralWidget(ui->graphicsView);
    this->setContentsMargins(0, 0, 0, 0);
    this->showMaximized();
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupGrid() {
    qreal s = 20.0;
    int gridWidth = SizeX;
    int gridHeight = SizeY;

    qreal width = s * 3 / 2;
    qreal height = sqrt(3) * s / 2;

    for (int i = 0; i < gridHeight; ++i) {
        for (int j = 0; j < gridWidth; ++j) {
            qreal x = j * width;
            qreal y = i * height * 2;

            if (j % 2 == 1) {
                y += height;
            }

            Hexagon* hex = new Hexagon(scene, 0, 0, s);
            grid[i][j] = hex;
            hex->setPos(x, y);
        }
    }

    ant = LangtonAnt((gridWidth / 2), (gridHeight / 2), 0);
    antItem = new AntItem(scene, (gridWidth / 2 ), (gridHeight / 2));
}


void MainWindow::updateLangtonAnt() {
    int gridX = ant.getX();
    int gridY = ant.getY();

    Hexagon* currentHex = grid[gridY][gridX];

    currentHex->setState(!currentHex->getState());

    if (currentHex->getState()) {
        ant.turnRight();
    } else {
        ant.turnLeft();
    }

    ant.move();

    antItem->updatePosition(ant.getX(), ant.getY());

    scene->update();
}
