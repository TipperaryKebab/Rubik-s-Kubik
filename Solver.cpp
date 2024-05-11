//
// Created by fasol on 5/7/2024.
//

#include <iostream>
#include "Solver.h"


int count = 0;

bool firstStepComplete(Cube &C){

    // Проверка на крест

    if (C.getComponent(1, 0, 0).getBottom() == 1
    && C.getComponent(0, 0, 1).getBottom() == 1
    && C.getComponent(1, 0, 2).getBottom() == 1
    && C.getComponent(2, 0, 1).getBottom() == 1
    && C.getComponent(1, 0, 0).getFront() == 2
    && C.getComponent(1, 1, 0).getFront() == 2
    && C.getComponent(0, 0, 1).getLeft() == 5
    && C.getComponent(0, 1, 1).getLeft() == 5
    && C.getComponent(1, 0, 2).getBack() == 4
    && C.getComponent(1, 1, 2).getBack() == 4
    && C.getComponent(2, 0, 1).getRight() == 3
    && C.getComponent(2, 1, 1).getRight() == 3)
        return true;
    return false;
}

void firstStepConfigurations(Cube &C){
    if (count == 4) {
        count = 0;
        return;
    }

    if (C.getComponent(1, 2, 0).getTop() == 1
    && C.getComponent(1, 2, 0).getFront() == 2) {
        C.front180();

    } else if (C.getComponent(2, 2, 1).getTop() == 1
    && C.getComponent(2, 2, 1).getRight() == 3) {
        C.right180();

    } else if (C.getComponent(0, 2, 1).getTop() == 1
    && C.getComponent(0, 2, 1).getLeft() == 5) {
        C.left180();

    } else if (C.getComponent(1, 2, 2).getTop() == 1
    && C.getComponent(1, 2, 2).getBack() == 4) {
        C.back180();

    } else if (C.getComponent(1, 2, 0).getTop() == 2
    && C.getComponent(1, 2, 0).getFront() == 1) {
        C.topAntiClockwise();
        C.rightAntiClockwise();
        C.frontClockwise();
        C.rightClockwise();

    } else if (C.getComponent(2, 2, 1).getTop() == 3
    && C.getComponent(2, 2, 1).getRight() == 1) {
        C.topAntiClockwise();
        C.backAntiClockwise();
        C.rightClockwise();
        C.backClockwise();

    } else if (C.getComponent(0, 2, 1).getTop() == 5
    && C.getComponent(0, 2, 1).getLeft() == 1) {
        C.topAntiClockwise();
        C.frontAntiClockwise();
        C.leftClockwise();
        C.frontClockwise();

    } else if (C.getComponent(1, 2, 2).getTop() == 4
    && C.getComponent(1, 2, 2).getBack() == 1) {
        C.topAntiClockwise();
        C.leftAntiClockwise();
        C.backClockwise();
        C.leftClockwise();

    } else if (C.getComponent(2, 1, 0).getFront() == 1) {
        C.frontAntiClockwise();
        C.topAntiClockwise();
        C.frontClockwise();

    } else if (C.getComponent(2, 1, 2).getRight() == 1) {
        C.rightAntiClockwise();
        C.topAntiClockwise();
        C.rightClockwise();

    } else if (C.getComponent(0, 1, 0).getLeft() == 1) {
        C.leftAntiClockwise();
        C.topAntiClockwise();
        C.leftClockwise();

    } else if (C.getComponent(0, 1, 2).getBack() == 1) {
        C.backAntiClockwise();
        C.topAntiClockwise();
        C.backClockwise();

    } else if (C.getComponent(0, 1, 0).getFront() == 1) {
        C.frontClockwise();
        C.topAntiClockwise();
        C.frontAntiClockwise();

    } else if (C.getComponent(2, 1, 0).getRight() == 1) {
        C.rightClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();

    } else if (C.getComponent(0, 1, 2).getLeft() == 1) {
        C.leftClockwise();
        C.topAntiClockwise();
        C.leftAntiClockwise();

    } else if (C.getComponent(2, 1, 2).getBack() == 1) {
        C.backClockwise();
        C.topAntiClockwise();
        C.backAntiClockwise();

    } else if (C.getComponent(1, 0, 0).getFront() == 1) {
        C.front180();
        C.topAntiClockwise();
        C.front180();

    } else if (C.getComponent(2, 0, 1).getRight() == 1) {
        C.right180();
        C.topAntiClockwise();
        C.right180();

    } else if (C.getComponent(0, 0, 1).getLeft() == 1) {
        C.left180();
        C.topAntiClockwise();
        C.left180();

    } else if (C.getComponent(1, 0, 2).getBack() == 1) {
        C.back180();
        C.topAntiClockwise();
        C.back180();

    } else if (C.getComponent(1, 0, 0).getFront() != 2
    && C.getComponent(1, 0, 0).getBottom() == 1) {
        C.front180();
        C.topAntiClockwise();
        C.front180();

    } else if (C.getComponent(2, 0, 1).getRight() != 3
    && C.getComponent(2, 0, 1).getBottom() == 1) {
        C.right180();
        C.topAntiClockwise();
        C.right180();

    } else if (C.getComponent(0, 0, 1).getLeft() != 5
    && C.getComponent(0, 0, 1).getBottom() == 1) {
        C.left180();
        C.topAntiClockwise();
        C.left180();

    } else if (C.getComponent(1, 0, 2).getBack() != 4
    && C.getComponent(1, 0, 2).getBottom() == 1) {
        C.back180();
        C.topAntiClockwise();
        C.back180();

    } else {
        count++;
        C.topClockwise();
        firstStepConfigurations(C);
    }
}

bool secondStepComplete(Cube &C) {

    // Проверка на полный крест

    if (C.getComponent(0, 0, 0).getBottom() == 1
        && C.getComponent(0, 0, 0).getFront() == 2
        && C.getComponent(0, 0, 0).getLeft() == 5

        && C.getComponent(2, 0, 0).getBottom() == 1
        && C.getComponent(2, 0, 0).getFront() == 2
        && C.getComponent(2, 0, 0).getRight()== 3

        && C.getComponent(0, 0, 2).getLeft() == 5
        && C.getComponent(0, 0, 2).getBottom() == 1
        && C.getComponent(0, 0, 2).getBack() == 4

        && C.getComponent(2, 0, 2).getRight() == 3
        && C.getComponent(2, 0, 2).getBottom() == 1
        && C.getComponent(2, 0, 2).getBack() == 4)
        return true;
    return false;

}

void secondStepConfigurations(Cube &C){
    if (count == 4){
        count = 0;
        return;
    }

    if (C.getComponent(2, 2 ,0).getTop() == 2
            && C.getComponent(2, 2, 0).getFront() == 1
            && C.getComponent(2, 2, 0).getRight() == 3) {
        C.frontAntiClockwise();
        C.topAntiClockwise();
        C.frontClockwise();
    } else if (C.getComponent(0, 2 ,0).getTop() == 5
            && C.getComponent(0, 2, 0).getFront() == 2
            && C.getComponent(0, 2, 0).getLeft() == 1) {
        C.leftAntiClockwise();
        C.topAntiClockwise();
        C.leftClockwise();
    } else if (C.getComponent(2, 2 ,2).getTop() == 3
               && C.getComponent(2, 2, 2).getBack() == 4
               && C.getComponent(2, 2, 2).getRight() == 1) {
        C.rightAntiClockwise();
        C.topAntiClockwise();
        C.rightClockwise();

    } else if (C.getComponent(0, 2 ,2).getTop() == 4
               && C.getComponent(0, 2, 2).getBack() == 1
               && C.getComponent(0, 2, 2).getLeft() == 5) {
        C.backAntiClockwise();
        C.topAntiClockwise();
        C.backClockwise();

    } else if (C.getComponent(2, 2 ,0).getTop() == 3
               && C.getComponent(2, 2, 0).getFront() == 2
               && C.getComponent(2, 2, 0).getRight() == 1) {
        C.rightClockwise();
        C.topClockwise();
        C.rightAntiClockwise();

    } else if (C.getComponent(0, 2 ,0).getTop() == 2
               && C.getComponent(0, 2, 0).getFront() == 1
               && C.getComponent(0, 2, 0).getLeft() == 5) {
        C.frontClockwise();
        C.topClockwise();
        C.frontAntiClockwise();

    } else if (C.getComponent(2, 2 ,2).getTop() == 4
               && C.getComponent(2, 2, 2).getBack() == 1
               && C.getComponent(2, 2, 2).getRight() == 3) {
        C.backClockwise();
        C.topClockwise();
        C.backAntiClockwise();

    } else if (C.getComponent(0, 2 ,2).getTop() == 5
               && C.getComponent(0, 2, 2).getBack() == 4
               && C.getComponent(0, 2, 2).getLeft() == 1) {
        C.leftClockwise();
        C.topClockwise();
        C.leftAntiClockwise();

    } else if (C.getComponent(2, 2 ,0).getTop() == 1
               && C.getComponent(2, 2, 0).getFront() == 3
               && C.getComponent(2, 2, 0).getRight() == 2) {
        C.rightClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();
        C.top180();
        C.rightClockwise();
        C.topClockwise();
        C.rightAntiClockwise();

    } else if (C.getComponent(0, 2 ,0).getTop() == 1
               && C.getComponent(0, 2, 0).getFront() == 5
               && C.getComponent(0, 2, 0).getLeft() == 2) {
        C.frontClockwise();
        C.topAntiClockwise();
        C.frontAntiClockwise();
        C.top180();
        C.frontClockwise();
        C.topClockwise();
        C.frontAntiClockwise();
    } else if (C.getComponent(2, 2 ,2).getTop() == 1
               && C.getComponent(2, 2, 2).getBack() == 3
               && C.getComponent(2, 2, 2).getRight() == 4) {
        C.backClockwise();
        C.topAntiClockwise();
        C.backAntiClockwise();
        C.top180();
        C.backClockwise();
        C.topClockwise();
        C.backAntiClockwise();
    } else if (C.getComponent(0, 2 ,2).getTop() == 1
               && C.getComponent(0, 2, 2).getBack() == 5
               && C.getComponent(0, 2, 2).getLeft() == 4) {
        C.leftClockwise();
        C.topAntiClockwise();
        C.leftAntiClockwise();
        C.top180();
        C.leftClockwise();
        C.topClockwise();
        C.leftAntiClockwise();
    } else if (C.getComponent(2, 0 ,0).getFront() == 1) {
        C.frontAntiClockwise();
        C.topAntiClockwise();
        C.frontClockwise();
    } else if (C.getComponent(0, 0 ,0).getLeft() == 1) {
        C.leftAntiClockwise();
        C.topAntiClockwise();
        C.leftClockwise();
    } else if (C.getComponent(2, 0 ,2).getRight() == 1) {
        C.rightAntiClockwise();
        C.topAntiClockwise();
        C.rightClockwise();
    } else if (C.getComponent(0, 0,2).getBack() == 1) {
        C.backAntiClockwise();
        C.topAntiClockwise();
        C.backClockwise();
    }
    else if (C.getComponent(2, 0 ,0).getRight() == 1) {
        C.frontAntiClockwise();
        C.topAntiClockwise();
        C.frontClockwise();
    } else if (C.getComponent(0, 0 ,0).getFront() == 1) {
        C.leftAntiClockwise();
        C.topAntiClockwise();
        C.leftClockwise();
    } else if (C.getComponent(2, 0 ,2).getBack() == 1) {
        C.rightAntiClockwise();
        C.topAntiClockwise();
        C.rightClockwise();
    } else if (C.getComponent(0, 0,2).getLeft() == 1) {
        C.backAntiClockwise();
        C.topAntiClockwise();
        C.backClockwise();

    } else if (C.getComponent(0, 0 ,0).getBottom() == 1
            && (C.getComponent(0, 0 ,0).getFront() != 2
            || C.getComponent(0, 0 ,0).getLeft() != 5)) {
        C.frontClockwise();
        C.topAntiClockwise();
        C.frontAntiClockwise();
    } else if (C.getComponent(2, 0 ,0).getBottom() == 1
               && (C.getComponent(2, 0 ,0).getFront() != 2
                   || C.getComponent(2, 0 ,0).getRight() != 3)) {
        C.rightClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();
    } else if (C.getComponent(2, 0 ,2).getBottom() == 1
               && (C.getComponent(2, 0 ,2).getBack() != 4
                   || C.getComponent(2, 0 ,2).getRight() != 3)) {
        C.backClockwise();
        C.topAntiClockwise();
        C.backAntiClockwise();
    } else if (C.getComponent(0, 0 ,2).getBottom() == 1
               && (C.getComponent(0, 0 ,2).getBack() != 4
                   || C.getComponent(0, 0 ,2).getLeft() != 5)) {
        C.leftClockwise();
        C.topAntiClockwise();
        C.leftAntiClockwise();

    } else {
        count++;
        C.topClockwise();
        secondStepConfigurations(C);
    }
}

bool thirdStepComplete(Cube &C) {

    // Проверка на полный крест

    if (C.getComponent(0, 1, 0).getFront() == 2
        && C.getComponent(0, 1, 0).getLeft() == 5

        && C.getComponent(2, 1, 0).getFront() == 2
        && C.getComponent(2, 1, 0).getRight()== 3

        && C.getComponent(0, 1, 2).getLeft() == 5
        && C.getComponent(0, 1, 2).getBack() == 4

        && C.getComponent(2, 1, 2).getRight() == 3
        && C.getComponent(2, 1, 2).getBack() == 4)
        return true;
    return false;

}

void thirdStepConfigurations(Cube &C){
    if (thirdStepComplete(C)){
        return;
    }

    if (count == 4) {
        count = 0;
        if (C.getComponent(2, 1, 0).getFront() != 2
                || C.getComponent(2, 1, 0).getRight() != 3) {
            C.topClockwise();
            C.rightClockwise();
            C.topAntiClockwise();
            C.rightAntiClockwise();
            C.topAntiClockwise();
            C.frontAntiClockwise();
            C.topClockwise();
            C.frontClockwise();

            std::cout << "636'3'6'2'62\n";

            thirdStepConfigurations(C);
        } else if (C.getComponent(0, 1, 0).getFront() != 2
                   || C.getComponent(0, 1, 0).getLeft() != 5) {
            C.topClockwise();
            C.frontClockwise();
            C.topAntiClockwise();
            C.frontAntiClockwise();
            C.topAntiClockwise();
            C.leftAntiClockwise();
            C.topClockwise();
            C.leftClockwise();

            std::cout << "626'2'6'5'65\n";

            thirdStepConfigurations(C);
        } else if (C.getComponent(0, 1, 2).getBack() != 4
                   || C.getComponent(0, 1, 2).getLeft() != 5) {
            C.topClockwise();
            C.leftClockwise();
            C.topAntiClockwise();
            C.leftAntiClockwise();
            C.topAntiClockwise();
            C.backAntiClockwise();
            C.topClockwise();
            C.backClockwise();

            std::cout << "656'5'6'4'64\n";

            thirdStepConfigurations(C);
        } else if (C.getComponent(2, 1, 2).getBack() != 4
                   || C.getComponent(2, 1, 2).getRight() != 3) {
            C.topClockwise();
            C.backClockwise();
            C.topAntiClockwise();
            C.backAntiClockwise();
            C.topAntiClockwise();
            C.rightAntiClockwise();
            C.topClockwise();
            C.rightClockwise();

            std::cout << "646'4'6'3'63\n";

            thirdStepConfigurations(C);
        } else {
            return;
        }
    }
    if (C.getComponent(1, 2, 0).getTop() == 5
            && C.getComponent(1, 2, 0).getFront() == 2) {
        C.topAntiClockwise();
        C.leftAntiClockwise();
        C.topClockwise();
        C.leftClockwise();
        C.topClockwise();
        C.frontClockwise();
        C.topAntiClockwise();
        C.frontAntiClockwise();

        std::cout << "6'5'65626'2'\n";
    } else if (C.getComponent(2, 2, 1).getTop() == 2
               && C.getComponent(2, 2, 1).getRight() == 3) {
        C.topAntiClockwise();
        C.frontAntiClockwise();
        C.topClockwise();
        C.frontClockwise();
        C.topClockwise();
        C.rightClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();

        std::cout << "6'2'62636'3'\n";
    } else if (C.getComponent(1, 2, 2).getTop() == 3
               && C.getComponent(1, 2, 2).getBack() == 4) {
        C.topAntiClockwise();
        C.rightAntiClockwise();
        C.topClockwise();
        C.rightClockwise();
        C.topClockwise();
        C.backClockwise();
        C.topAntiClockwise();
        C.backAntiClockwise();

        std::cout << "6'3'63646'4'\n";
    } else if (C.getComponent(0, 2, 1).getTop() == 4
               && C.getComponent(0, 2, 1).getLeft() == 5) {
        C.topAntiClockwise();
        C.backAntiClockwise();
        C.topClockwise();
        C.backClockwise();
        C.topClockwise();
        C.leftClockwise();
        C.topAntiClockwise();
        C.leftAntiClockwise();

        std::cout << "6'4'64656'5'\n";
    } else if (C.getComponent(1, 2, 0).getTop() == 3
               && C.getComponent(1, 2, 0).getFront() == 2) {
        C.topClockwise();
        C.rightClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();
        C.topAntiClockwise();
        C.frontAntiClockwise();
        C.topClockwise();
        C.frontClockwise();
    // TODO :: BEEN HERE
        std::cout << "636'3'6'2'62\n";
    } else if (C.getComponent(0, 2, 1).getTop() == 2
            && C.getComponent(0, 2, 1).getLeft() == 5) {
        C.topClockwise();
        C.frontClockwise();
        C.topAntiClockwise();
        C.frontAntiClockwise();
        C.topAntiClockwise();
        C.leftAntiClockwise();
        C.topClockwise();
        C.leftClockwise();
        // TODO :: BEEN HERE
        std::cout << "626'2'6'5'65\n";
    } else if (C.getComponent(1, 2, 2).getTop() == 5
            && C.getComponent(1, 2, 2).getBack() == 4) {
        C.topClockwise();
        C.leftClockwise();
        C.topAntiClockwise();
        C.leftAntiClockwise();
        C.topAntiClockwise();
        C.backAntiClockwise();
        C.topClockwise();
        C.backClockwise();

        std::cout << "656'5'6'4'64\n";
    } else if (C.getComponent(2, 2, 1).getTop() == 4
               && C.getComponent(2, 2, 1).getRight() == 3) {
        C.topClockwise();
        C.backClockwise();
        C.topAntiClockwise();
        C.backAntiClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();
        C.topClockwise();
        C.rightClockwise();

        std::cout << "646'4'6'3'63\n";
    } else {
        count++;
        C.topClockwise();
        thirdStepConfigurations(C);
    }
}

bool fourthStepComplete(Cube &C){
    if (C.getComponent(1,2,0).getTop() == 6
            && C.getComponent(2,2,1).getTop() == 6
            && C.getComponent(0,2,1).getTop() == 6
            && C.getComponent(1,2,2).getTop() == 6){
        return true;
    }
    return false;
}

void fourthStepConfigurations(Cube &C){
    if (C.getComponent(1,2,0).getFront() == 6
    && C.getComponent(2,2,1).getRight() == 6
    && C.getComponent(0,2,1).getTop() == 6
    && C.getComponent(1,2,2).getTop() == 6){
        C.frontClockwise();
        C.topClockwise();
        C.rightClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();
        C.frontAntiClockwise();
    } else if (C.getComponent(1,2,0).getFront() == 6
               && C.getComponent(0,2,1).getLeft() == 6
               && C.getComponent(2,2,1).getTop() == 6
               && C.getComponent(1,2,2).getTop() == 6){
        C.leftClockwise();
        C.topClockwise();
        C.frontClockwise();
        C.topAntiClockwise();
        C.frontAntiClockwise();
        C.leftAntiClockwise();
    } else if (C.getComponent(1,2,0).getTop() == 6
            && C.getComponent(0,2,1).getTop() == 6
            && C.getComponent(2,2,1).getRight() == 6
            && C.getComponent(1,2,2).getBack() == 6){
        C.rightClockwise();
        C.topClockwise();
        C.backClockwise();
        C.topAntiClockwise();
        C.backAntiClockwise();
        C.rightAntiClockwise();
    } else if (C.getComponent(1,2,0).getTop() == 6
               && C.getComponent(2,2,1).getTop() == 6
               && C.getComponent(0,2,1).getLeft() == 6
               && C.getComponent(1,2,2).getBack() == 6){
        C.backClockwise();
        C.topClockwise();
        C.leftClockwise();
        C.topAntiClockwise();
        C.leftAntiClockwise();
        C.backAntiClockwise();
    } else if (C.getComponent(1,2,0).getFront() == 6
               && C.getComponent(2,2,1).getTop() == 6
               && C.getComponent(0,2,1).getTop() == 6
               && C.getComponent(1,2,2).getBack() == 6){
        C.frontClockwise();
        C.rightClockwise();
        C.topClockwise();
        C.rightAntiClockwise();
        C.topAntiClockwise();
        C.frontAntiClockwise();
    } else if (C.getComponent(1,2,0).getTop() == 6
               && C.getComponent(2,2,1).getRight() == 6
               && C.getComponent(0,2,1).getLeft() == 6
               && C.getComponent(1,2,2).getTop() == 6){
        C.rightClockwise();
        C.backClockwise();
        C.topClockwise();
        C.backAntiClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();
    } else if (C.getComponent(1,2,0).getFront() == 6
              && C.getComponent(2,2,1).getRight() == 6
              && C.getComponent(0,2,1).getLeft() == 6
              && C.getComponent(1,2,2).getBack() == 6){
        C.frontClockwise();
        C.topClockwise();
        C.rightClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();
        C.frontAntiClockwise();
        C.rightClockwise();
        C.backClockwise();
        C.topClockwise();
        C.backAntiClockwise();
        C.topAntiClockwise();
        C.rightAntiClockwise();
    }
}

void fifthStepConfigurations(Cube &C){
    if (C.getComponent(2, 2, 1).getRight() == 2){
        C.topClockwise();
        C.leftAntiClockwise();
        C.top180();
        C.leftClockwise();
        C.topClockwise();
        C.leftAntiClockwise();
        C.topClockwise();
        C.leftClockwise();
    } else if (C.getComponent(0, 2, 1).getLeft() == 2){
        C.topClockwise();
        C.backAntiClockwise();
        C.top180();
        C.backClockwise();
        C.topClockwise();
        C.backAntiClockwise();
        C.topClockwise();
        C.backClockwise();
    } else if (C.getComponent(1,2,2).getBack() == 2){
        C.topClockwise();
        C.rightAntiClockwise();
        C.top180();
        C.rightClockwise();
        C.topClockwise();
        C.rightAntiClockwise();
        C.topClockwise();
        C.rightClockwise();
        C.topClockwise();
        C.backAntiClockwise();
        C.top180();
        C.backClockwise();
        C.topClockwise();
        C.backAntiClockwise();
        C.topClockwise();
        C.backClockwise();
        C.topClockwise();
        C.rightAntiClockwise();
        C.top180();
        C.rightClockwise();
        C.topClockwise();
        C.rightAntiClockwise();
        C.topClockwise();
        C.rightClockwise();
    }

    if (C.getComponent(1,2,2).getBack() == 3){
        C.topClockwise();
        C.frontAntiClockwise();
        C.top180();
        C.frontClockwise();
        C.topClockwise();
        C.frontAntiClockwise();
        C.topClockwise();
        C.frontClockwise();
    } else if (C.getComponent(0,2,1).getLeft() == 3){
        C.topClockwise();
        C.backAntiClockwise();
        C.top180();
        C.backClockwise();
        C.topClockwise();
        C.backAntiClockwise();
        C.topClockwise();
        C.backClockwise();
        C.topClockwise();
        C.leftAntiClockwise();
        C.top180();
        C.leftClockwise();
        C.topClockwise();
        C.leftAntiClockwise();
        C.topClockwise();
        C.leftClockwise();
        C.topClockwise();
        C.backAntiClockwise();
        C.top180();
        C.backClockwise();
        C.topClockwise();
        C.backAntiClockwise();
        C.topClockwise();
        C.backClockwise();
    }

    if (C.getComponent(0,2,1).getLeft() == 4){
        C.topClockwise();
        C.rightAntiClockwise();
        C.top180();
        C.rightClockwise();
        C.topClockwise();
        C.rightAntiClockwise();
        C.topClockwise();
        C.rightClockwise();
    }

}

bool sixthStepComplete(Cube &C){
    if (((C.getComponent(0,2,0).getLeft() == 2
         && C.getComponent(0,2,0).getFront() == 5
         && C.getComponent(0,2,0).getTop() == 6)

        || (C.getComponent(0,2,0).getLeft() == 2
            && C.getComponent(0,2,0).getFront() == 6
            && C.getComponent(0,2,0).getTop() == 5)

        || (C.getComponent(0,2,0).getLeft() == 5
            && C.getComponent(0,2,0).getFront() == 2
            && C.getComponent(0,2,0).getTop() == 6)

        || (C.getComponent(0,2,0).getLeft() == 5
            && C.getComponent(0,2,0).getFront() == 6
            && C.getComponent(0,2,0).getTop() == 2)

        || (C.getComponent(0,2,0).getLeft() == 6
            && C.getComponent(0,2,0).getFront() == 2
            && C.getComponent(0,2,0).getTop() == 5)

        || (C.getComponent(0,2,0).getLeft() == 6
            && C.getComponent(0,2,0).getFront() == 5
            && C.getComponent(0,2,0).getTop() == 2))

            &&

        ((C.getComponent(2,2,2).getRight() == 3
            && C.getComponent(2,2,2).getBack() == 4
            && C.getComponent(2,2,2).getTop() == 6)

        || (C.getComponent(2,2,2).getRight() == 3
            && C.getComponent(2,2,2).getBack() == 6
            && C.getComponent(2,2,2).getTop() == 4)

        || (C.getComponent(2,2,2).getRight() == 4
            && C.getComponent(2,2,2).getBack() == 3
            && C.getComponent(2,2,2).getTop() == 6)

        || (C.getComponent(2,2,2).getRight() == 4
            && C.getComponent(2,2,2).getBack() == 6
            && C.getComponent(2,2,2).getTop() == 3)

        || (C.getComponent(2,2,2).getRight() == 6
            && C.getComponent(2,2,2).getBack() == 3
            && C.getComponent(2,2,2).getTop() == 4)

        || (C.getComponent(2,2,2).getRight() == 6
            && C.getComponent(2,2,2).getBack() == 4
            && C.getComponent(2,2,2).getTop() == 3))

            &&

        (C.getComponent(0,2,2).getBack() == 4
            && C.getComponent(0,2,2).getLeft() == 5
            && C.getComponent(0,2,2).getTop() == 6)

        || (C.getComponent(0,2,2).getBack() == 4
            && C.getComponent(0,2,2).getLeft() == 6
            && C.getComponent(0,2,2).getTop() == 5)

        || (C.getComponent(0,2,2).getBack() == 5
            && C.getComponent(0,2,2).getLeft() == 4
            && C.getComponent(0,2,2).getTop() == 6)

        || (C.getComponent(0,2,2).getBack() == 5
            && C.getComponent(0,2,2).getLeft() == 6
            && C.getComponent(0,2,2).getTop() == 4)

        || (C.getComponent(0,2,2).getBack() == 6
            && C.getComponent(0,2,2).getLeft() == 4
            && C.getComponent(0,2,2).getTop() == 5)

        || (C.getComponent(0,2,2).getBack() == 6
            && C.getComponent(0,2,2).getLeft() == 5
            && C.getComponent(0,2,2).getTop() == 4)

        &&

        (C.getComponent(2,2,0).getFront() == 2
            && C.getComponent(2,2,0).getRight() == 3
            && C.getComponent(2,2,0).getTop() == 6)

           || (C.getComponent(2,2,0).getFront() == 2
               && C.getComponent(2,2,0).getRight() == 6
               && C.getComponent(2,2,0).getTop() == 3)

           || (C.getComponent(2,2,0).getFront() == 3
               && C.getComponent(2,2,0).getRight() == 2
               && C.getComponent(2,2,0).getTop() == 6)

           || (C.getComponent(2,2,0).getFront() == 3
               && C.getComponent(2,2,0).getRight() == 6
               && C.getComponent(2,2,0).getTop() == 2)

           || (C.getComponent(2,2,0).getFront() == 6
               && C.getComponent(2,2,0).getRight() == 2
               && C.getComponent(2,2,0).getTop() == 3)

           || (C.getComponent(2,2,0).getFront() == 6
               && C.getComponent(2,2,0).getRight() == 3
               && C.getComponent(2,2,0).getTop() == 6))
            return true;
    return false;
}

void sixthStepConfigurations(Cube &C){
    if ((C.getComponent(0,2,0).getLeft() == 2
        && C.getComponent(0,2,0).getFront() == 3
        && C.getComponent(0,2,0).getTop() == 6)

    || (C.getComponent(0,2,0).getLeft() == 2
        && C.getComponent(0,2,0).getFront() == 6
        && C.getComponent(0,2,0).getTop() == 3)

    || (C.getComponent(0,2,0).getLeft() == 3
        && C.getComponent(0,2,0).getFront() == 2
        && C.getComponent(0,2,0).getTop() == 6)

    || (C.getComponent(0,2,0).getLeft() == 3
        && C.getComponent(0,2,0).getFront() == 6
        && C.getComponent(0,2,0).getTop() == 2)

    || (C.getComponent(0,2,0).getLeft() == 6
        && C.getComponent(0,2,0).getFront() == 2
        && C.getComponent(0,2,0).getTop() == 3)

    || (C.getComponent(0,2,0).getLeft() == 6
        && C.getComponent(0,2,0).getFront() == 3
        && C.getComponent(0,2,0).getTop() == 2)){

        C.frontAntiClockwise();
        C.leftAntiClockwise();
        C.frontClockwise();
        C.rightAntiClockwise();
        C.frontAntiClockwise();
        C.leftClockwise();
        C.frontClockwise();
        C.rightClockwise();

    } else if ((C.getComponent(2,2,2).getRight() == 2
               && C.getComponent(2,2,2).getBack() == 3
               && C.getComponent(2,2,2).getTop() == 6)

            || (C.getComponent(2,2,2).getRight() == 2
                && C.getComponent(2,2,2).getBack() == 6
                && C.getComponent(2,2,2).getTop() == 3)

            || (C.getComponent(2,2,2).getRight() == 3
               && C.getComponent(2,2,2).getBack() == 2
               && C.getComponent(2,2,2).getTop() == 6)

            || (C.getComponent(2,2,2).getRight() == 3
               && C.getComponent(2,2,2).getBack() == 6
               && C.getComponent(2,2,2).getTop() == 2)

            || (C.getComponent(2,2,2).getRight() == 6
               && C.getComponent(2,2,2).getBack() == 2
               && C.getComponent(2,2,2).getTop() == 3)

            || (C.getComponent(2,2,2).getRight() == 6
               && C.getComponent(2,2,2).getBack() == 3
               && C.getComponent(2,2,2).getTop() == 2)){

        C.rightAntiClockwise();
        C.frontAntiClockwise();
        C.leftAntiClockwise();
        C.frontClockwise();
        C.rightClockwise();
        C.frontAntiClockwise();
        C.leftClockwise();
        C.frontClockwise();

    } else if ((C.getComponent(0,2,2).getBack() == 2
                   && C.getComponent(0,2,2).getLeft() == 3
                   && C.getComponent(0,2,2).getTop() == 6)

               || (C.getComponent(0,2,2).getBack() == 2
                   && C.getComponent(0,2,2).getLeft() == 6
                   && C.getComponent(0,2,2).getTop() == 3)

               || (C.getComponent(0,2,2).getBack() == 3
                   && C.getComponent(0,2,2).getLeft() == 2
                   && C.getComponent(0,2,2).getTop() == 6)

               || (C.getComponent(0,2,2).getBack() == 3
                  && C.getComponent(0,2,2).getLeft() == 6
                  && C.getComponent(0,2,2).getTop() == 2)

               || (C.getComponent(0,2,2).getBack() == 6
                  && C.getComponent(0,2,2).getLeft() == 2
                  && C.getComponent(0,2,2).getTop() == 3)

               || (C.getComponent(0,2,2).getBack() == 6
                  && C.getComponent(0,2,2).getLeft() == 3
                  && C.getComponent(0,2,2).getTop() == 2)){

        C.frontAntiClockwise();
        C.leftAntiClockwise();
        C.backAntiClockwise();
        C.leftClockwise();
        C.frontClockwise();
        C.leftAntiClockwise();
        C.backClockwise();
        C.leftClockwise();

    } else {
        if ((C.getComponent(0,2,0).getLeft() == 3
        && C.getComponent(0,2,0).getFront() == 4
        && C.getComponent(0,2,0).getTop() == 6)

        || (C.getComponent(0,2,0).getLeft() == 3
            && C.getComponent(0,2,0).getFront() == 6
            && C.getComponent(0,2,0).getTop() == 4)

        || (C.getComponent(0,2,0).getLeft() == 4
            && C.getComponent(0,2,0).getFront() == 3
            && C.getComponent(0,2,0).getTop() == 6)

        || (C.getComponent(0,2,0).getLeft() == 4
            && C.getComponent(0,2,0).getFront() == 6
            && C.getComponent(0,2,0).getTop() == 3)

        ||  (C.getComponent(0,2,0).getLeft() == 6
           && C.getComponent(0,2,0).getFront() == 3
           && C.getComponent(0,2,0).getTop() == 4)

        || (C.getComponent(0,2,0).getLeft() == 6
            && C.getComponent(0,2,0).getFront() == 4
            && C.getComponent(0,2,0).getTop() == 3)){

            C.backAntiClockwise();
            C.rightAntiClockwise();
            C.backClockwise();
            C.leftAntiClockwise();
            C.backAntiClockwise();
            C.rightClockwise();
            C.backClockwise();
            C.leftClockwise();

        } else if ((C.getComponent(0,2,2).getBack() == 3
        && C.getComponent(0,2,2).getLeft() == 4
        && C.getComponent(0,2,2).getTop() == 6)

        || (C.getComponent(0,2,2).getBack() == 3
            && C.getComponent(0,2,2).getLeft() == 6
            && C.getComponent(0,2,2).getTop() == 4)

        || (C.getComponent(0,2,2).getBack() == 4
            && C.getComponent(0,2,2).getLeft() == 3
            && C.getComponent(0,2,2).getTop() == 6)

        || (C.getComponent(0,2,2).getBack() == 4
            && C.getComponent(0,2,2).getLeft() == 6
            && C.getComponent(0,2,2).getTop() == 3)

        || (C.getComponent(0,2,2).getBack() == 6
            && C.getComponent(0,2,2).getLeft() == 3
            && C.getComponent(0,2,2).getTop() == 4)

        || (C.getComponent(0,2,2).getBack() == 6
            && C.getComponent(0,2,2).getLeft() == 4
            && C.getComponent(0,2,2).getTop() == 3)){

            C.leftAntiClockwise();
            C.backClockwise();
            C.rightAntiClockwise();
            C.backClockwise();
            C.leftClockwise();
            C.backAntiClockwise();
            C.rightClockwise();
            C.backClockwise();
        }
    }
}

bool seventhStepComplete(Cube &C){
    if (C.getComponent(0,2,0).getTop() == 6
        && C.getComponent(0,2,0).getFront() == 2
        && C.getComponent(0,2,0).getLeft() == 5
        && C.getComponent(2,2,0).getTop() == 6
        && C.getComponent(2,2,0).getFront() == 2
        && C.getComponent(2,2,0).getRight() == 3
        && C.getComponent(0,2,2).getTop() == 6
        && C.getComponent(0,2,2).getBack() == 4
        && C.getComponent(0,2,2).getLeft() == 5
        && C.getComponent(2,2,2).getTop() == 6
        && C.getComponent(2,2,2).getBack() == 4
        && C.getComponent(2,2,2).getRight() == 3)
        return true;
    return false;
}

void seventhStepConfigurations(Cube &C){
    if (seventhStepComplete(C))
        return;

    if (C.getComponent(2,2,0).getRight() == 6){
        C.frontAntiClockwise();
        C.rightClockwise();
        C.frontClockwise();
        C.rightAntiClockwise();
        C.frontAntiClockwise();
        C.rightClockwise();
        C.frontClockwise();
        C.rightAntiClockwise();

        if (count > 0){
            C.topClockwise();
            //seventhStepConfigurations(C);
            count = 0;
            return;
        }
    } else if (C.getComponent(2,2,0).getFront() == 6){
        C.rightClockwise();
        C.frontAntiClockwise();
        C.rightAntiClockwise();
        C.frontClockwise();
        C.rightClockwise();
        C.frontAntiClockwise();
        C.rightAntiClockwise();
        C.frontClockwise();

        if (count > 0){
            C.topClockwise();
            //seventhStepConfigurations(C);
            count = 0;
            return;
        }
    } else {
        count++;
        C.topClockwise();
        //seventhStepConfigurations(C);
        return;
    }
}

void cubeSolution(Cube &C) {

    while (!firstStepComplete(C) || !secondStepComplete(C)
    || !thirdStepComplete(C) || !fourthStepComplete(C)) {
        while (!firstStepComplete(C)) {
            firstStepConfigurations(C);
        }

        while (!secondStepComplete(C)) {
            secondStepConfigurations(C);
        }

        while (!thirdStepComplete(C)) {
            thirdStepConfigurations(C);
        }

        while (!fourthStepComplete(C)) {
            fourthStepConfigurations(C);
        }

        fifthStepConfigurations(C);
    }

    for(int i = 0; i < 100; i++){
        sixthStepConfigurations(C);
    }

    for(int i = 0; i < 50; i++) {
        seventhStepConfigurations(C);
    }
}
