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

    QMenu *fileMenu = ui->menubar->addMenu(tr("&File"));
    fileMenu->addAction(tr("Open map"), this, &MainWindow::openMap);
    fileMenu->addAction(tr("Save map"), this, &MainWindow::saveMap);
    ui->menubar->addAction(tr("Start/Pause"), this, &MainWindow::startPause);
    ui->menubar->addAction(tr("Change speed"), this, &MainWindow::changeSpeed);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    grid = *new QVector<QVector<Hexagon*>>(SizeY,QVector<Hexagon*>(SizeX));

    setupGrid();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLangtonAnt);
    timer->start(isFastest?0:100);

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
    antItem->updatePosition(ant.getX(), ant.getY());
}


void MainWindow::updateLangtonAnt() {
    if (!isPaused) {
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
}

void MainWindow::startPause(){
    isPaused = !isPaused;
    scene->update();
}

void MainWindow::changeSpeed(){
    isFastest = !isFastest;
    timer->setInterval(isFastest?0:100);
}

void MainWindow::openMap(){
    openMap0(grid, ant, "state.txt");
}

void MainWindow::saveMap(){
    saveMap0(grid, ant, "state.txt");
}


void MainWindow::openMap0(QVector<QVector<Hexagon*>>& grid, LangtonAnt& ant, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        QMessageBox::critical(nullptr, "Ошибка", "Файл не найден. Сначала выполните сохранение.");
        return;
    }
    int row = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int col = 0;
        int state;

        while (iss >> state) {
            grid[row][col]->setState(state);
            col++;
        }

        row++;
        if (row >= SizeY) {
            break;
        }
    }

    if (std::getline(file, line)) {
        std::istringstream iss(line);
        int posX, posY, direction;

        iss >> posX >> posY >> direction;

        ant.setState(posX,posY,direction);
    }

    file.close();
}

void MainWindow::saveMap0(QVector<QVector<Hexagon*>>& grid, LangtonAnt& ant, const std::string& filename){
    std::ofstream file(filename);

    for (const auto& row : grid) {
        for (const auto& hex : row) {
            file << hex->getState() << " ";
        }
        file << std::endl;
    }

    file << ant.getX() << " " << ant.getY() << " " << ant.getDirection() << std::endl;

    file.close();
}
