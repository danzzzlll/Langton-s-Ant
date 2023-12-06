#include "langtonant.h"
#include <cmath>
#include "QtGlobal"

LangtonAnt::LangtonAnt(int x, int y, int direction) : x(x), y(y), direction(direction) {}

void LangtonAnt::move() {
    int sizeX = SizeX;
    int sizeY = SizeY;

    switch (direction) {
        case 0: // Up
            y -= 1;
            break;
        case 1: // Up-right
            x += 1;
            if (x % 2 != 0) y -= 1;
            break;
        case 2: // Down-right
            x += 1;
            if (x % 2 == 0) y += 1;
            break;
        case 3: // Down
            y += 1;
            break;
        case 4: // Down-left
            x -= 1;
            if (x % 2 == 0) y += 1;
            break;
        case 5: // Up-left
            x -= 1;
            if (x % 2 != 0) y -= 1;
            break;
        default:
            break;
    }

    if (x < 0) {
        x += sizeX;
    } else if (x >= sizeX) {
        x -= sizeX;
    }

    if (y < 0) {
        y += sizeY;
    } else if (y >= sizeY) {
        y -= sizeY;
    }
}


void LangtonAnt::turnLeft() {
    direction = (direction + 5) % 6;
}

void LangtonAnt::turnRight() {
    direction = (direction + 1) % 6;
}

int LangtonAnt::getX() const {
    return x;
}

int LangtonAnt::getY() const {
    return y;
}
