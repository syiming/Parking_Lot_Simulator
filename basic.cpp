//
// Created by delight on 2016/12/12.
//
#include <iostream>
#include <GL/glut.h>
#include "basic.h"
using namespace std;
//---------------------------------------------------------------------------------------------------------------------//
Rect::Rect(Vec anchor, Vec dia1,Vec dia2, Vec dia3, Vec dia4, float r, float g, float b)
        : anchor(anchor),dia1(dia1),dia2(dia2),dia3(dia3),dia4(dia4),r(r),g(g),b(b){}
void Rect::draw() {
    glColor3f(r, g, b);glBegin(GL_QUADS);
    glVertex2f(anchor.x + dia1.x,anchor.y + dia1.y); glVertex2f(anchor.x + dia2.x,anchor.y + dia2.y);
    glVertex2f(anchor.x + dia3.x,anchor.y + dia3.y); glVertex2f(anchor.x + dia4.x,anchor.y + dia4.y);
    glEnd();
}
//---------------------------------------------------------------------------------------------------------------------//
Trian::Trian(Vec anchor, Vec vec1, Vec vec2, Vec vec3, float r, float g, float b)
        :anchor(anchor),vec1(vec1),vec2(vec2),vec3(vec3),r(r),g(g),b(b){}
void Trian::draw() {
    glColor3f(r, g, b); glBegin(GL_TRIANGLES);
    glVertex2f(anchor.x + vec1.x, anchor.y + vec1.y);
    glVertex2f(anchor.x + vec2.x, anchor.y + vec2.y);
    glVertex2f(anchor.x + vec3.x, anchor.y + vec3.y);
    glEnd();
}
//---------------------------------------------------------------------------------------------------------------------//
static const double PI=3.14159;
Circle::Circle(Vec anchor):anchor(anchor) {
    r = 1; g = 127.0/255; b = 36.0/255; R=0.032;
}
void Circle::draw() {
    glColor3f(r, g, b); glBegin(GL_TRIANGLE_FAN);
    glVertex2f(anchor.x, anchor.y);
    for (int i=0;i<1001;i++) {
        glVertex2f((GLfloat)(anchor.x+R*cos(i*2*PI/1000)),(GLfloat)(anchor.y+R*sin(i*2*PI/1000)));
    }
    glEnd();
}
//---------------------------------------------------------------------------------------------------------------------//
HalfCir::HalfCir(Vec anchor, float theta) : anchor(anchor), theta(theta){r = 0; g = 0; b = 1; R =0.08; };
void HalfCir::draw() {
    glColor3f(r, g, b); glBegin(GL_TRIANGLE_FAN);
    glVertex2f(anchor.x, anchor.y);
    for (int i=0;i<501;i++) {
        glVertex2f((GLfloat)(anchor.x+R*cos(i*2*PI/1000+theta)),(GLfloat)(anchor.y+R*sin(i*2*PI/1000+theta)));
    }
    glEnd();
}
//---------------------------------------------------------------------------------------------------------------------//
Line::Line(Vec anchor, float theta) : anchor(anchor){
    r = 1 ; g = 0.5; b = 0; vec1 = vec1<<theta; vec2 = vec2<<theta;
}
void Line::draw() {
    glColor3f(r, g, b);glBegin(GL_LINES);
    glVertex2f(anchor.x+vec1.x,anchor.y+vec1.y);glVertex2f(anchor.x+vec1.x*1.5,anchor.y+vec1.y*1.5);
    glVertex2f(anchor.x+vec2.x,anchor.y+vec2.y);glVertex2f(anchor.x+vec2.x*1.5,anchor.y+vec2.y*1.5);
    glEnd();

}
//---------------------------------------------------------------------------------------------------------------------//
Trapezium::Trapezium(Vec anchor, Vec vec1, Vec vec2, Vec vec3, Vec vec4, float r, float g, float b)
        : anchor(anchor), vec1(vec1), vec2(vec2), vec3(vec3), vec4(vec4), r(r), g(g), b(b){};
void Trapezium::draw() {
    glColor3f(r, g, b);glBegin(GL_QUADS);
    glVertex2f(anchor.x+vec1.x, anchor.y+vec1.y); glVertex2f(anchor.x+vec2.x, anchor.y+vec2.y);
    glVertex2f(anchor.x+vec3.x, anchor.y+vec3.y); glVertex2f(anchor.x+vec4.x, anchor.y+vec4.y);
    glEnd();
}


