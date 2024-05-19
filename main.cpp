#include <stdlib.h>
#include <iostream>

#include <cmath>
#include <random>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Component.h"
#include "Cube.h"
#include "Solver.h"

GLfloat controlX = 0.0, controlY = 0.0;
GLfloat controlNegX = 0.0, controlNegY = 0.0;

bool solving = false;

Cube Rubik;

void shuffle(Cube &C){
    int r = rand() % 1037;
    for(int i = 0; i < r; i++){
        int m = rand() % 18;
        if (m == 1){
            C.topClockwise();
        } else if (m == 2){
            C.topAntiClockwise();
        } else if (m == 3){
            C.top180();
        } else if (m == 4){
            C.frontClockwise();
        } else if (m == 5){
            C.frontAntiClockwise();
        } else if (m == 6){
            C.front180();
        } else if (m == 7){
            C.bottomClockwise();
        } else if (m == 8){
            C.bottomAntiClockwise();
        } else if (m == 9){
            C.bottom180();
        } else if (m == 10){
            C.leftClockwise();
        } else if (m == 11){
            C.leftAntiClockwise();
        } else if (m == 12){
            C.left180();
        } else if (m == 13){
            C.rightClockwise();
        } else if (m == 14){
            C.rightAntiClockwise();
        } else if (m == 15){
            C.right180();
        } else if (m == 16){
            C.backClockwise();
        } else if (m == 17){
            C.backAntiClockwise();
        } else if (m == 18){
            C.back180();
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0, 0, 0,
              0, 0, -1,
              0, 1, 0);

    glRotatef(controlX, 1, 0, 0);
    glRotatef(controlY, 0, 1, 0);

    glRotatef(controlNegX, 1, 0, 0);
    glRotatef(controlNegY, 0, 1, 0);

    Rubik.cubeDraw();

    glutSwapBuffers();
}

int toggleMove = 1;

void processKeyboard(unsigned char key, int x, int y){
    if (key == 'q' || key == 'Q') {
        toggleMove = 1;
    } else if (key == 'w' || key == 'W') {
        toggleMove = 2;
    } else if (key == 'e' || key == 'E') {
        toggleMove = 3;
    } else if (key == '1'){
        if (toggleMove == 1) {
            Rubik.bottomClockwise();
        } else if (toggleMove == 2) {
            Rubik.bottomAntiClockwise();
        } else {
            Rubik.bottom180();
        }
    } else if (key == '2'){
        if (toggleMove == 1) {
            Rubik.frontClockwise();
        } else if (toggleMove == 2) {
            Rubik.frontAntiClockwise();
        } else {
            Rubik.front180();
        }
    } else if (key == '3') {
        if (toggleMove == 1) {
            Rubik.rightClockwise();
        } else if (toggleMove == 2) {
            Rubik.rightAntiClockwise();
        } else {
            Rubik.right180();
        }
    } else if (key == '4') {
        if (toggleMove == 1) {
            Rubik.backClockwise();
        } else if (toggleMove == 2) {
            Rubik.backAntiClockwise();
        } else {
            Rubik.back180();
        }
    } else if (key == '5') {
        if (toggleMove == 1) {
            Rubik.leftClockwise();
        } else if (toggleMove == 2) {
            Rubik.leftAntiClockwise();
        } else {
            Rubik.left180();
        }
    } else if (key == '6') {
        if (toggleMove == 1) {
            Rubik.topClockwise();
        } else if (toggleMove == 2) {
            Rubik.topAntiClockwise();
        } else {
            Rubik.top180();
        }
    } else if (key == 's') {
        solving = true;
    } else if (key == 'd') {
        seventhStepConfigurations(Rubik);
    } else if (key == 'f') {
        shuffle(Rubik);
    }
}

void processSpecialKeys(int key, int x, int y){
    if (key == GLUT_KEY_LEFT)
        controlY += 1.5;
    else if (key == GLUT_KEY_RIGHT)
        controlNegY -= 1.5;
    else if (key == GLUT_KEY_DOWN)
        controlNegX -= 1.5;
    else if (key == GLUT_KEY_UP)
        controlX += 1.5;
}

int width = 600, height = 600;

void timer(int value) {
    if (solving){
        for(int i = 0; i < 3; i++) {
            cubeSolution(Rubik);
            cubeSolution(Rubik);
        }
        solving = false;
    }
    glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(processKeyboard);
    glutPostRedisplay(); // Вызываем функцию display для обновления изображения
    glutTimerFunc(85, timer, 0); // Устанавливаем таймер повторного вызова
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Rubik's Cube");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutTimerFunc(100, timer, 0); // Устанавливаем таймер
    glutMainLoop();
    return 0;
}