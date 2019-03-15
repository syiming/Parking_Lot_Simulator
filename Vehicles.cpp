//
// Created by delight on 2016/12/12.
//
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Vehicles.h"
using namespace std;
UFO::UFO(const Vec &anchor, float theta, int slot) : anchor(anchor),theta(theta),start_point(-0.8,-1){setSlot(slot);}
UFO::~UFO() {  }
void UFO::draw() {
    rotate();
    move();
    ufo[0] = new HalfCir(anchor,theta);
    ufo[1] = new Line(anchor,theta);
    Vec veca = {0.055,0.015};
    Vec vecb = {-0.055,0.015};
    veca = veca<<theta;
    vecb = vecb<<theta;
    Vec vec1 = {0.02,0.015};
    Vec vec2 = {0.03,-0.015};
    Vec vec3 = {-0.03,-0.015};
    Vec vec4 = {-0.02,0.015};
    ufo[2] = new Trapezium({anchor.x-veca.x,anchor.y-veca.y},vec1<<theta,vec2<<theta,vec3<<theta,vec4<<theta,1,0.8,0);
    ufo[3] = new Trapezium({anchor.x-vecb.x,anchor.y-vecb.y},vec1<<theta,vec2<<theta,vec3<<theta,vec4<<theta,1,0.8,0);
    for (int i = 0;i<4;i++) ufo[i]->draw();
    for (int i=0;i<4;i++) delete ufo[i];
}
//---------------------------------------------------------------------------------------------------------------------//
Car::Car(const Vec &anchor, float theta, int slot) : anchor(anchor),theta(theta),start_point(-0.8,-1){ setSlot(slot);}
Car::~Car() {}
void Car::draw() {
    move();
    Vec dia1 = {0.13,0.04}; dia1 = dia1<<theta;
    Vec dia2 = {0.13,-0.04}; dia2 = dia2<<theta;
    Vec dia3 = {-0.13,-0.04}; dia3 = dia3<<theta;
    Vec dia4 = {-0.13,0.04}; dia4 = dia4<<theta;
    Vec vec2 = {0.068,0.04}; vec2 = vec2<<theta;
    Vec vec3 = {-0.068,0.04}; vec3 = vec3<<theta;
    Vec vec4 = {0,0.08}; vec4 = vec4<<theta;
    Vec vec5 = {0.06,0.03};
    Vec vec6 = {0.08,-0.04};
    Vec vec7 = {-0.08,-0.04};
    Vec vec8 = {-0.06,0.03};
    car[0] = new Rect(anchor,dia1,dia2,dia3,dia4,1,200/255.0,150/255.0);
    car[1] = new Circle((Vec){anchor.x-vec2.x,anchor.y-vec2.y});
    car[2] = new Circle((Vec){anchor.x-vec3.x,anchor.y-vec3.y});
    car[3] = new Trapezium({anchor.x+vec4.x,anchor.y+vec4.y},vec5<<theta,vec6<<theta,vec7<<theta,vec8<<theta,159.0/255,121.0/255,238.0/255);
    for (int i=0;i<4;i++) car[i]->draw();
    for (int i=0;i<4;i++) delete car[i];
}
//---------------------------------------------------------------------------------------------------------------------//
Spacecraft::Spacecraft(const Vec &anchor, float theta, double w, int slot) : anchor(anchor), theta(theta),start_point(-0.8,-1) { setSlot(slot); }
Spacecraft::~Spacecraft() {}
void Spacecraft::draw() {
    move();
    zoom();
    Vec rect1_dia1 = {0.035,0.1}; rect1_dia1 = rect1_dia1<<theta;
    Vec rect1_dia2 = {0.035,-0.1};rect1_dia2 = rect1_dia2<<theta;
    Vec rect1_dia3 = {-0.035,-0.1};rect1_dia3 = rect1_dia3<<theta;
    Vec rect1_dia4 = {-0.035,0.1};rect1_dia4 = rect1_dia4<<theta;
    Vec rect2_dia1 = {0.01,0.025}; rect2_dia1 = rect2_dia1<<theta;
    Vec rect2_dia2 = {0.01,-0.025};rect2_dia2 = rect2_dia2<<theta;
    Vec rect2_dia3 = {-0.01,-0.025};rect2_dia3 = rect2_dia3<<theta;
    Vec rect2_dia4 = {-0.01,0.025};rect2_dia4 = rect2_dia4<<theta;
    Vec to_2 = {0.0,-0.02};to_2 = to_2<<theta;
    Vec rect3_dia1 = {0.0075,0.01}; rect3_dia1 = rect3_dia1<<theta;
    Vec rect3_dia2 = {0.0075,-0.01};rect3_dia2 = rect3_dia2<<theta;
    Vec rect3_dia3 = {-0.0075,-0.01};rect3_dia3 = rect3_dia3<<theta;
    Vec rect3_dia4 = {-0.0075,0.01};rect3_dia4 = rect3_dia4<<theta;
    Vec to_3 = {0.015,0.05}; to_3 = to_3<<theta;
    Vec to_4 = {-0.015,0.05}; to_4 = to_4<<theta;
    Vec tri1_1 = {-0.035,-0.1}; tri1_1 = tri1_1<<theta;
    Vec tri1_2 = {-0.035,0}; tri1_2 = tri1_2<<theta;
    Vec tri1_3 = {-0.085,-0.1}; tri1_3 = tri1_3<<theta;
    Vec tri2_1 = {0.035,-0.1}; tri2_1 = tri2_1<<theta;
    Vec tri2_2 = {0.035,0}; tri2_2 = tri2_2<<theta;
    Vec tri2_3 = {0.085,-0.1}; tri2_3 = tri2_3<<theta;
    Vec tri3_1 = {-0.035,0.1}; tri3_1 = tri3_1<<theta;
    Vec tri3_2 = {0.035,0.1}; tri3_2 = tri3_2<<theta;
    Vec tri3_3 = {0,0.2}; tri3_3 = tri3_3<<theta;
    Vec trape1 = {0.02,0.02}; trape1 = trape1<<theta;
    Vec trape2 = {0.03,-0.02}; trape2 = trape2<<theta;
    Vec trape3 = {-0.03,-0.02}; trape3 = trape3<<theta;
    Vec trape4 = {-0.02,0.02}; trape4 = trape4<<theta;
    Vec tot = {0,-0.12}; tot = tot<<theta;
    spacecraft[0] = new Rect(anchor, rect1_dia1*w, rect1_dia2*w, rect1_dia3*w, rect1_dia4*w, 1,246.0/255,143.0/255);
    spacecraft[1] = new Rect({anchor.x+to_2.x*w,anchor.y+to_2.y*w},rect2_dia1*w,rect2_dia2*w,rect2_dia3*w,rect2_dia4*w,0,191.0/255,1);
    spacecraft[2] = new Rect({anchor.x+to_3.x*w,anchor.y+to_3.y*w},rect3_dia1*w,rect3_dia2*w,rect3_dia3*w,rect3_dia4*w,1,0,0);
    spacecraft[3] = new Rect({anchor.x+to_4.x*w,anchor.y+to_4.y*w},rect3_dia1*w,rect3_dia2*w,rect3_dia3*w,rect3_dia4*w,1,0,0);
    spacecraft[4] = new Trian(anchor,tri1_1*w,tri1_2*w,tri1_3*w,1,153/255.0,18/255.0);
    spacecraft[5] = new Trian(anchor,tri2_1*w,tri2_2*w,tri2_3*w,1,153/255.0,18/255.0);
    spacecraft[6] = new Trian(anchor,tri3_1*w,tri3_2*w,tri3_3*w,100/255.0,150/255.0,90/255.0);
    spacecraft[7] = new Trapezium({anchor.x+tot.x*w,anchor.y+tot.y*w},trape1*w,trape2*w,trape3*w,trape4*w,0,0,0);
    for (int i = 0;i<8;i++) spacecraft[i]->draw();
    for (int i=0;i<8;i++) delete spacecraft[i];
}
void Spacecraft::zoom() {
    int static i = 0;
    if (w >= 0.5 && i == 0) {
        w /= 1.2;
    }
    else if (w <= 1) {
        i = 1;
        w *= 1.2;
    }
    else i = 0;
}
//---------------------------------------------------------------------------------------------------------------------//
Door::Door(const Vec &anchor) : anchor(anchor) {}
Door::~Door() {}
void Door::draw() {
    float r, g, b;
    setcolor(&r,&g,&b);
    door = new Rect(anchor,{0.11,0.16}, {0.11,-0.16}, {-0.11,-0.16}, {-0.11,0.16},r,g,b);
    door->draw();
    delete door;
};
void Door::setcolor(float *r, float *g, float *b) {
    *r = (float) rand() / RAND_MAX;
    *g = (float) rand() / RAND_MAX;
    *b = (float) rand() / RAND_MAX;
}
