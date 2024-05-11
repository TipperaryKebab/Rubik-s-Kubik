//
// Created by fasol on 4/21/2024.
//

#ifndef RUBIK_KUBIK_CUBE_H
#define RUBIK_KUBIK_CUBE_H


#include "Component.h"

class Cube {
    // TODO: bricks[X][Y][Z] = CXYZ
    Component bricks[3][3][3];
public:
    Cube();

    Component getComponent(int x, int y, int z);

    void cubeDraw();

    // TODO: Грани

    // Bottom - red
    void bottomClockwise();
    void bottomAntiClockwise();
    void bottom180();

    // Top - green
    void topClockwise();
    void topAntiClockwise();
    void top180();

    // Front - blue
    void frontClockwise();
    void frontAntiClockwise();
    void front180();

    // Back - yellow
    void backClockwise();
    void backAntiClockwise();
    void back180();

    // Left - purple
    void leftClockwise();
    void leftAntiClockwise();
    void left180();

    // Right - cyan
    void rightClockwise();
    void rightAntiClockwise();
    void right180();


};


#endif //RUBIK_KUBIK_CUBE_H
