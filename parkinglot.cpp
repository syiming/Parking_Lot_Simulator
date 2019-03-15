//
// Created by delight on 2016/12/12.
//
#include <iostream>
#include "parkinglot.h"
#include <GL/glut.h>
using namespace std;
void parkinglot::vehin(int slot_num, int type) {
    if (slot[slot_num]==NULL) {
        switch (type) {
            case 1:
                slot[slot_num] = new Car({-0.8, -1}, 3.14/2, slot_num);
                break;
            case 2:
                slot[slot_num] = new UFO({-0.8, -1}, 0, slot_num);
                break;
            case 3:
                slot[slot_num] = new Spacecraft({-0.8, -1}, 0, 1, slot_num);
                break;
            default:
                cerr << "error in vehin!";
        }
    }
}
void parkinglot::vehout() {
    for(int i = 0 ; i<10; i++) {
        if ((slot[i] != NULL) && (1 == (slot[i]->getOut()))) {
            delete slot[i];
            slot[i] = NULL;
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------//
void parkinglot::draw() {
    glColor3f(0.5, 0.5, 0.5); glBegin(GL_LINES);
    glVertex2f((GLfloat)-0.6, (GLfloat)-0.75); glVertex2f(0.94, (GLfloat)-0.75);
    glVertex2f(0.6, 0.75); glVertex2f((GLfloat)-0.94, 0.75);
    glVertex2f((GLfloat)-0.94, 0.75); glVertex2f((GLfloat)-0.94, (GLfloat)-0.9);
    glVertex2f(0.94, 0.9); glVertex2f(0.94, (GLfloat)-0.75);
    glVertex2f((GLfloat)-0.6, (GLfloat)-0.4); glVertex2f((GLfloat)-0.6, (GLfloat)-0.9);
    glVertex2f((GLfloat)-0.36, (GLfloat)-0.75); glVertex2f((GLfloat)-0.36, (GLfloat)-0.4);
    glVertex2f((GLfloat)-0.12, (GLfloat)-0.75); glVertex2f((GLfloat)-0.12, (GLfloat)-0.4);
    glVertex2f(0.12, (GLfloat)-0.75); glVertex2f(0.12, (GLfloat)-0.4);
    glVertex2f(0.6, (GLfloat)-0.4); glVertex2f(0.6, (GLfloat)-0.75);
    glVertex2f(0.36, (GLfloat)-0.75); glVertex2f(0.36, (GLfloat)-0.4);
    glVertex2f((GLfloat)-0.6, 0.4); glVertex2f((GLfloat)-0.6, 0.75);
    glVertex2f((GLfloat)-0.36, 0.75); glVertex2f((GLfloat)-0.36, 0.4);
    glVertex2f((GLfloat)-0.12, 0.75); glVertex2f((GLfloat)-0.12, 0.4);
    glVertex2f(0.12, 0.75); glVertex2f(0.12, 0.4);
    glVertex2f(0.6, 0.4); glVertex2f(0.6, 0.9);
    glVertex2f(0.36, 0.75); glVertex2f(0.36, 0.4);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f((GLfloat)-0.6,0.08); glVertex2f(0.6, 0.08);
    glVertex2f(0.6, (GLfloat)-0.08); glVertex2f((GLfloat)-0.6, (GLfloat)-0.08); glEnd();
    for (int i = 0;i<10;i++){
        if (slot[i]!=NULL){
            slot[i]->draw();
        }
        Sleep(4);
    }
}
