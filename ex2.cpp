#include "basic.h"
#include "parkinglot.h"
#include "Vehicles.h"

void TimeStep(int n) {
    glutTimerFunc(25, TimeStep, 0); glutPostRedisplay();
}

void glDraw() {
    int static i = 0; int snum,type;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (i<=15){
        snum = rand()%10;
        type = rand()%3+1;
        if (i == 0) parkinglot::getInstance()->vehin(snum,type);
        i++;
    }
    else {i = 0;}
    parkinglot::getInstance()->draw();
    parkinglot::getInstance()->vehout();
    glutSwapBuffers();glFlush();
}

int ex2 (int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Parking Lot");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 0);
    glutMainLoop();
}