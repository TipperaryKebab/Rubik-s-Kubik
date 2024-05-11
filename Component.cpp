//
// Created by fasol on 4/21/2024.
//

#include <string>

#include "Component.h"

using namespace std;

const float LEN = 0.475 / 2;

Component::Component(GLfloat x, GLfloat y, GLfloat z) {
    X = x;
    Y = y;
    Z = z;
}

Component::Component() {}

void Component::changeColors(Component &C){
    top[0] = C.top[0], top[1] = C.top[1], top[2] = C.top[2];
    bottom[0] = C.bottom[0], bottom[1] = C.bottom[1], bottom[2] = C.bottom[2];
    left[0] = C.left[0], left[1] = C.left[1], left[2] = C.left[2];
    right[0] = C.right[0], right[1] = C.right[1], right[2] = C.right[2];
    front[0] = C.front[0], front[1] = C.front[1], front[2] = C.front[2];
    back[0] = C.back[0], back[1] = C.back[1], back[2] = C.back[2];
}

void Component::draw(){
    //glLoadIdentity();
    glPushMatrix();

    glTranslatef(X / 2, Y / 2, Z / 2); // Перемещаем куб по оси Z

    // Передняя грань
    glBegin(GL_QUADS);
    glColor3f(front[0], front[1], front[2]);
    //glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(-LEN / 2, -LEN / 2, -LEN / 2);
    glVertex3f(-LEN / 2, LEN / 2, -LEN / 2);
    glVertex3f(LEN / 2, LEN / 2, -LEN / 2);
    glVertex3f(LEN / 2, -LEN / 2, -LEN / 2);
    //glEnd();

    // Задняя грань
    //glBegin(GL_QUADS);
    glColor3f(back[0], back[1], back[2]);
    //glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(-LEN / 2, -LEN / 2, LEN / 2);
    glVertex3f(-LEN / 2, LEN / 2, LEN / 2);
    glVertex3f(LEN / 2, LEN / 2, LEN / 2);
    glVertex3f(LEN / 2, -LEN / 2, LEN / 2);
    //glEnd();

    // Левая грань
    //glBegin(GL_QUADS);
    glColor3f(left[0], left[1], left[2]);
    //glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-LEN / 2, LEN / 2, LEN / 2);
    glVertex3f(-LEN / 2, LEN / 2, -LEN / 2);
    glVertex3f(-LEN / 2, -LEN / 2, -LEN / 2);
    glVertex3f(-LEN / 2, -LEN / 2, LEN / 2);
    //glEnd();

    // Правая грань
    //glBegin(GL_QUADS);
    glColor3f(right[0], right[1], right[2]);
    //glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(LEN / 2, LEN / 2, LEN / 2);
    glVertex3f(LEN / 2, -LEN / 2, LEN / 2);
    glVertex3f(LEN / 2, -LEN / 2, -LEN / 2);
    glVertex3f(LEN / 2, LEN / 2, -LEN / 2);
    //glEnd();

    // Верхняя грань
    //glBegin(GL_QUADS);
    glColor3f(top[0], top[1], top[2]);
    //glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-LEN / 2, LEN / 2, -LEN / 2);
    glVertex3f(-LEN / 2, LEN / 2, LEN / 2);
    glVertex3f(LEN / 2, LEN / 2, LEN / 2);
    glVertex3f(LEN / 2, LEN / 2, -LEN / 2);
    //glEnd();

    // Нижняя грань
    //glBegin(GL_QUADS);
    glColor3f(bottom[0], bottom[1], bottom[2]);
    //glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-LEN / 2, -LEN / 2, -LEN / 2);
    glVertex3f(LEN / 2, -LEN / 2, -LEN / 2);
    glVertex3f(LEN / 2, -LEN / 2, LEN / 2);
    glVertex3f(-LEN / 2, -LEN / 2, LEN / 2);
    glEnd();

    glPopMatrix();
}

void Component::bm_ft_tp_bk() {
    // Bottom -> Front -> Top -> Back
    float temp[3] = {back[0], back[1], back[2]};
    back[0] = top[0], back[1] = top[1], back[2] = top[2];
    top[0] = front[0], top[1] = front[1], top[2] = front[2];
    front[0] = bottom[0], front[1] = bottom[1], front[2] = bottom[2];
    bottom[0] = temp[0], bottom[1] = temp[1], bottom[2] = temp[2];
}

void Component::bk_tp_ft_bm() {
    // Back -> Top -> Front -> Bottom
    float temp[3] = {bottom[0], bottom[1], bottom[2]};
    bottom[0] = front[0], bottom[1] = front[1], bottom[2] = front[2];
    front[0] = top[0], front[1] = top[1], front[2] = top[2];
    top[0] = back[0], top[1] = back[1], top[2] = back[2];
    back[0] = temp[0], back[1] = temp[1], back[2] = temp[2];
}

void Component::bm_rt_tp_lt() {
    // Bottom -> Right -> Top -> Left
    float temp[3] = {left[0], left[1], left[2]};
    left[0] = top[0], left[1] = top[1], left[2] = top[2];
    top[0] = right[0], top[1] = right[1], top[2] = right[2];
    right[0] = bottom[0], right[1] = bottom[1], right[2] = bottom[2];
    bottom[0] = temp[0], bottom[1] = temp[1], bottom[2] = temp[2];
}

void Component::lt_tp_rt_bm() {
    // Left -> Top -> Right -> Bottom
    float temp[3] = {bottom[0], bottom[1], bottom[2]};
    bottom[0] = right[0], bottom[1] = right[1], bottom[2] = right[2];
    right[0] = top[0], right[1] = top[1], right[2] = top[2];
    top[0] = left[0], top[1] = left[1], top[2] = left[2];
    left[0] = temp[0], left[1] = temp[1], left[2] = temp[2];
}

void Component::rt_ft_lt_bk() {
    // Right -> Front -> Left -> Back
    float temp[3] = {back[0], back[1], back[2]};
    back[0] = left[0], back[1] = left[1], back[2] = left[2];
    left[0] = front[0], left[1] = front[1], left[2] = front[2];
    front[0] = right[0], front[1] = right[1], front[2] = right[2];
    right[0] = temp[0], right[1] = temp[1], right[2] = temp[2];
}

void Component::bk_lt_ft_rt() {
    // Back -> Left -> Front -> Right
    float temp[3] = {right[0], right[1], right[2]};
    right[0] = front[0], right[1] = front[1], right[2] = front[2];
    front[0] = left[0], front[1] = left[1], front[2] = left[2];
    left[0] = back[0], left[1] = back[1], left[2] = back[2];
    back[0] = temp[0], back[1] = temp[1], back[2] = temp[2];
}

int Component::getBottom() {
    if (bottom[0] == 1 && bottom[1] == 0 && bottom[2] == 0)
        return 1;
    else if (bottom[0] == 0 && bottom[1] == 0 && bottom[2] == 1)
        return 2;
    else if (bottom[0] == 0 && bottom[1] == 1 && bottom[2] == 1)
        return 3;
    else if (bottom[0] == 1 && bottom[1] == 1 && bottom[2] == 0)
        return 4;
    else if (bottom[0] == 1 && bottom[1] == 0 && bottom[2] == 1)
        return 5;
    else if (bottom[0] == 0 && bottom[1] == 1 && bottom[2] == 0)
        return 6;

    return -1;
}

int Component::getFront() {
    if (front[0] == 1 && front[1] == 0 && front[2] == 0)
        return 1;
    else if (front[0] == 0 && front[1] == 0 && front[2] == 1)
        return 2;
    else if (front[0] == 0 && front[1] == 1 && front[2] == 1)
        return 3;
    else if (front[0] == 1 && front[1] == 1 && front[2] == 0)
        return 4;
    else if (front[0] == 1 && front[1] == 0 && front[2] == 1)
        return 5;
    else if (front[0] == 0 && front[1] == 1 && front[2] == 0)
        return 6;

    return -1;
}

int Component::getRight() {
    if (right[0] == 1 && right[1] == 0 && right[2] == 0)
        return 1;
    else if (right[0] == 0 && right[1] == 0 && right[2] == 1)
        return 2;
    else if (right[0] == 0 && right[1] == 1 && right[2] == 1)
        return 3;
    else if (right[0] == 1 && right[1] == 1 && right[2] == 0)
        return 4;
    else if (right[0] == 1 && right[1] == 0 && right[2] == 1)
        return 5;
    else if (right[0] == 0 && right[1] == 1 && right[2] == 0)
        return 6;

    return -1;
}

int Component::getBack() {
    if (back[0] == 1 && back[1] == 0 && back[2] == 0)
        return 1;
    else if (back[0] == 0 && back[1] == 0 && back[2] == 1)
        return 2;
    else if (back[0] == 0 && back[1] == 1 && back[2] == 1)
        return 3;
    else if (back[0] == 1 && back[1] == 1 && back[2] == 0)
        return 4;
    else if (back[0] == 1 && back[1] == 0 && back[2] == 1)
        return 5;
    else if (back[0] == 0 && back[1] == 1 && back[2] == 0)
        return 6;

    return -1;
}

int Component::getLeft() {
    if (left[0] == 1 && left[1] == 0 && left[2] == 0)
        return 1;
    else if (left[0] == 0 && left[1] == 0 && left[2] == 1)
        return 2;
    else if (left[0] == 0 && left[1] == 1 && left[2] == 1)
        return 3;
    else if (left[0] == 1 && left[1] == 1 && left[2] == 0)
        return 4;
    else if (left[0] == 1 && left[1] == 0 && left[2] == 1)
        return 5;
    else if (left[0] == 0 && left[1] == 1 && left[2] == 0)
        return 6;

    return -1;
}

int Component::getTop() {
    if (top[0] == 1 && top[1] == 0 && top[2] == 0)
        return 1;
    else if (top[0] == 0 && top[1] == 0 && top[2] == 1)
        return 2;
    else if (top[0] == 0 && top[1] == 1 && top[2] == 1)
        return 3;
    else if (top[0] == 1 && top[1] == 1 && top[2] == 0)
        return 4;
    else if (top[0] == 1 && top[1] == 0 && top[2] == 1)
        return 5;
    else if (top[0] == 0 && top[1] == 1 && top[2] == 0)
        return 6;

    return -1;
}