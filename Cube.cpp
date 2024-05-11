//
// Created by fasol on 4/21/2024.
//

#include "Cube.h"

const GLfloat A = 0.50;


Cube::Cube() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                bricks[i][j][k] = Component(GLfloat(i - 1) * A, GLfloat(j - 1) * A, GLfloat(k - 1) * A);
}

void Cube::cubeDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                bricks[i][j][k].draw();
}

Component Cube::getComponent(int x, int y, int z) {
    return bricks[x][y][z];
}

void Cube::bottomClockwise() {

    Component temp = bricks[0][0][0];
    bricks[0][0][0].changeColors(bricks[0][0][2]);
    bricks[0][0][2].changeColors(bricks[2][0][2]);
    bricks[2][0][2].changeColors(bricks[2][0][0]);
    bricks[2][0][0].changeColors(temp);

    temp = bricks[1][0][0];
    bricks[1][0][0].changeColors(bricks[0][0][1]);
    bricks[0][0][1].changeColors(bricks[1][0][2]);
    bricks[1][0][2].changeColors(bricks[2][0][1]);
    bricks[2][0][1].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[i][0][j].bk_lt_ft_rt();
        }
    }
}

void Cube::bottomAntiClockwise() {

    Component temp = bricks[0][0][0];
    bricks[0][0][0].changeColors(bricks[2][0][0]);
    bricks[2][0][0].changeColors(bricks[2][0][2]);
    bricks[2][0][2].changeColors(bricks[0][0][2]);
    bricks[0][0][2].changeColors(temp);

    temp = bricks[1][0][0];
    bricks[1][0][0].changeColors(bricks[2][0][1]);
    bricks[2][0][1].changeColors(bricks[1][0][2]);
    bricks[1][0][2].changeColors(bricks[0][0][1]);
    bricks[0][0][1].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[i][0][j].rt_ft_lt_bk();
        }
    }
}

void Cube::bottom180() {
    bottomClockwise();
    bottomClockwise();
}

void Cube::topClockwise() {

    Component temp = bricks[0][2][0];
    bricks[0][2][0].changeColors(bricks[2][2][0]);
    bricks[2][2][0].changeColors(bricks[2][2][2]);
    bricks[2][2][2].changeColors(bricks[0][2][2]);
    bricks[0][2][2].changeColors(temp);

    temp = bricks[1][2][0];
    bricks[1][2][0].changeColors(bricks[2][2][1]);
    bricks[2][2][1].changeColors(bricks[1][2][2]);
    bricks[1][2][2].changeColors(bricks[0][2][1]);
    bricks[0][2][1].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[i][2][j].rt_ft_lt_bk();
        }
    }
}

void Cube::topAntiClockwise() {

    Component temp = bricks[0][2][0];
    bricks[0][2][0].changeColors(bricks[0][2][2]);
    bricks[0][2][2].changeColors(bricks[2][2][2]);
    bricks[2][2][2].changeColors(bricks[2][2][0]);
    bricks[2][2][0].changeColors(temp);

    temp = bricks[1][2][0];
    bricks[1][2][0].changeColors(bricks[0][2][1]);
    bricks[0][2][1].changeColors(bricks[1][2][2]);
    bricks[1][2][2].changeColors(bricks[2][2][1]);
    bricks[2][2][1].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[i][2][j].bk_lt_ft_rt();
        }
    }
}

void Cube::top180() {
    topClockwise();
    topClockwise();
}

void Cube::frontClockwise() {

    Component temp = bricks[0][0][0];
    bricks[0][0][0].changeColors(bricks[2][0][0]);
    bricks[2][0][0].changeColors(bricks[2][2][0]);
    bricks[2][2][0].changeColors(bricks[0][2][0]);
    bricks[0][2][0].changeColors(temp);

    temp = bricks[1][0][0];
    bricks[1][0][0].changeColors(bricks[2][1][0]);
    bricks[2][1][0].changeColors(bricks[1][2][0]);
    bricks[1][2][0].changeColors(bricks[0][1][0]);
    bricks[0][1][0].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[i][j][0].lt_tp_rt_bm();
        }
    }
}

// TODO: FIX this and backClockwise()

void Cube::frontAntiClockwise() {

    Component temp = bricks[0][0][0];
    bricks[0][0][0].changeColors(bricks[0][2][0]);
    bricks[0][2][0].changeColors(bricks[2][2][0]);
    bricks[2][2][0].changeColors(bricks[2][0][0]);
    bricks[2][0][0].changeColors(temp);

    temp = bricks[1][0][0];
    bricks[1][0][0].changeColors(bricks[0][1][0]);
    bricks[0][1][0].changeColors(bricks[1][2][0]);
    bricks[1][2][0].changeColors(bricks[2][1][0]);
    bricks[2][1][0].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[i][j][0].bm_rt_tp_lt();
        }
    }
}

void Cube::front180() {
    frontClockwise();
    frontClockwise();
}

void Cube::backClockwise() {

    Component temp = bricks[0][0][2];
    bricks[0][0][2].changeColors(bricks[0][2][2]);
    bricks[0][2][2].changeColors(bricks[2][2][2]);
    bricks[2][2][2].changeColors(bricks[2][0][2]);
    bricks[2][0][2].changeColors(temp);

    temp = bricks[1][0][2];
    bricks[1][0][2].changeColors(bricks[0][1][2]);
    bricks[0][1][2].changeColors(bricks[1][2][2]);
    bricks[1][2][2].changeColors(bricks[2][1][2]);
    bricks[2][1][2].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[i][j][2].bm_rt_tp_lt();
        }
    }
}

void Cube::backAntiClockwise() {

    Component temp = bricks[0][0][2];
    bricks[0][0][2].changeColors(bricks[2][0][2]);
    bricks[2][0][2].changeColors(bricks[2][2][2]);
    bricks[2][2][2].changeColors(bricks[0][2][2]);
    bricks[0][2][2].changeColors(temp);

    temp = bricks[1][0][2];
    bricks[1][0][2].changeColors(bricks[2][1][2]);
    bricks[2][1][2].changeColors(bricks[1][2][2]);
    bricks[1][2][2].changeColors(bricks[0][1][2]);
    bricks[0][1][2].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[i][j][2].lt_tp_rt_bm();
        }
    }
}

void Cube::back180() {
    backClockwise();
    backClockwise();
}

void Cube::leftClockwise() {

    Component temp = bricks[0][2][2];
    bricks[0][2][2].changeColors(bricks[0][0][2]);
    bricks[0][0][2].changeColors(bricks[0][0][0]);
    bricks[0][0][0].changeColors(bricks[0][2][0]);
    bricks[0][2][0].changeColors(temp);

    temp = bricks[0][1][0];
    bricks[0][1][0].changeColors(bricks[0][2][1]);
    bricks[0][2][1].changeColors(bricks[0][1][2]);
    bricks[0][1][2].changeColors(bricks[0][0][1]);
    bricks[0][0][1].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[0][i][j].bk_tp_ft_bm();
        }
    }
}

void Cube::leftAntiClockwise() {

    Component temp = bricks[0][2][2];
    bricks[0][2][2].changeColors(bricks[0][2][0]);
    bricks[0][2][0].changeColors(bricks[0][0][0]);
    bricks[0][0][0].changeColors(bricks[0][0][2]);
    bricks[0][0][2].changeColors(temp);

    temp = bricks[0][1][0];
    bricks[0][1][0].changeColors(bricks[0][0][1]);
    bricks[0][0][1].changeColors(bricks[0][1][2]);
    bricks[0][1][2].changeColors(bricks[0][2][1]);
    bricks[0][2][1].changeColors(temp);


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[0][i][j].bm_ft_tp_bk();
        }
    }
}

void Cube::left180() {
    leftClockwise();
    leftClockwise();
}

void Cube::rightClockwise() {

    Component temp = bricks[2][2][2];
    bricks[2][2][2].changeColors(bricks[2][2][0]);
    bricks[2][2][0].changeColors(bricks[2][0][0]);
    bricks[2][0][0].changeColors(bricks[2][0][2]);
    bricks[2][0][2].changeColors(temp);

    temp = bricks[2][1][0];
    bricks[2][1][0].changeColors(bricks[2][0][1]);
    bricks[2][0][1].changeColors(bricks[2][1][2]);
    bricks[2][1][2].changeColors(bricks[2][2][1]);
    bricks[2][2][1].changeColors(temp);


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[2][i][j].bm_ft_tp_bk();
        }
    }
}

void Cube::rightAntiClockwise() {

    Component temp = bricks[2][2][2];
    bricks[2][2][2].changeColors(bricks[2][0][2]);
    bricks[2][0][2].changeColors(bricks[2][0][0]);
    bricks[2][0][0].changeColors(bricks[2][2][0]);
    bricks[2][2][0].changeColors(temp);

    temp = bricks[2][1][0];
    bricks[2][1][0].changeColors(bricks[2][2][1]);
    bricks[2][2][1].changeColors(bricks[2][1][2]);
    bricks[2][1][2].changeColors(bricks[2][0][1]);
    bricks[2][0][1].changeColors(temp);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            bricks[2][i][j].bk_tp_ft_bm();
        }
    }
}

void Cube::right180() {
    rightClockwise();
    rightClockwise();
}