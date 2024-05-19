//
// Created by fasol on 5/7/2024.
//

#ifndef RUBIK_KUBIK_SOLVER_H
#define RUBIK_KUBIK_SOLVER_H

#include "Cube.h"

// TODO: Алгротим сборки написан по документации
// TODO:  "Визуализация сборки Кубика Рубика"
// TODO: https://is.ifmo.ru/download/brick.pdf

void cubeSolution(Cube &C);

bool firstStepComplete(Cube &C);
void firstStepConfigurations(Cube &C);

bool secondStepComplete(Cube &C);
void secondStepConfigurations(Cube &C);

bool thirdStepComplete(Cube &C);
void thirdStepConfigurations(Cube &C);

bool fourthStepComplete(Cube &C);
void fourthStepConfigurations(Cube &C);

bool fifthStepComplete(Cube &C);
void fifthStepConfigurations(Cube &C);

bool sixthStepComplete(Cube &C);
void sixthStepConfigurations(Cube &C);

bool seventhStepComplete(Cube &C);
void seventhStepConfigurations(Cube &C);

#endif //RUBIK_KUBIK_SOLVER_H
