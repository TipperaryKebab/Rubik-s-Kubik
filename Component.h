//
// Created by fasol on 4/21/2024.
//

#ifndef RUBIK_KUBIK_COMPONENT_H
#define RUBIK_KUBIK_COMPONENT_H

#include <GL/freeglut.h>

class Component {
    GLfloat X, Y, Z;
    float bottom[3] = {1.0, 0.0, 0.0}; // Красный
    float top[3] = {0.0, 1.0, 0.0}; // Зеленый
    float front[3] = {0.0, 0.0, 1.0}; // Синий
    float back[3] = {1.0, 1.0, 0.0}; // Желтый
    float left[3] = {1.0, 0.0, 1.0}; // Пурпурный
    float right[3] = {0.0, 1.0, 1.0}; // Бирюзовый
public:
    Component(GLfloat x, GLfloat y, GLfloat z);
    Component();

    void draw();

    void changeColors(Component &C);

    // TODO: Изменения цветов граней

    void bm_ft_tp_bk(); // Bottom -> Front -> Top -> Back
    void bk_tp_ft_bm(); // Back -> Top -> Front -> Bottom

    void bm_rt_tp_lt(); // Bottom -> Right -> Top -> Left
    void lt_tp_rt_bm(); // Left -> Top -> Right -> Bottom

    void rt_ft_lt_bk(); // Right -> Front -> Left -> Back
    void bk_lt_ft_rt(); // Back -> Left -> Front -> Back

    int getBottom();
    int getFront();
    int getRight();
    int getBack();
    int getLeft();
    int getTop();

};



#endif //RUBIK_KUBIK_COMPONENT_H
