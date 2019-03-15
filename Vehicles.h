//
// Created by delight on 2016/12/12.
//
#ifndef H8_VEHICLES_H
#define H8_VEHICLES_H
#include "basic.h"
using namespace std;
class UFO : public Figure {
public:
    UFO(const Vec &anchor, float theta, int slot);
    void draw(); // Draw out all its figures
    void move() {
        Vec _start_point(start_point);
        Vec _stop_point(0.8,1);
        float _start_theta;
        float _stop_theta;
        float v1, h1;
        if (slot/5 == 0) {
            v1 = -0.3;
            h1 = 0.56 + slot * 0.24;
        }
        else {
            v1 = 0.3;
            h1 = 0.56 + (slot - 5)*0.24;
        }
        switch(step1) {
            case 0:
                _stop_point = _start_point + Vec(0, (1 + v1));
                if((step2 == 8)|| (step2 == 9))
                    theta -= 3.14/8;
                break;
            case 1:
                _stop_point = _start_point + Vec(h1, 0);
                if((step2 == 0)|| (step2 == 1))
                    theta -= 3.14/8;
                break;
            case 2:
                _stop_point = _start_point + Vec(-0.24, 0);
                if((step2 == 8)|| (step2 == 9))
                    theta += 3.14/8;
                break;
            case 3:
                _stop_point = _start_point + Vec(0, v1);
                if((step2 == 0)|| (step2 == 1))
                    theta += 3.14/8;
                break;
            case 4:
                _stop_point = _start_point + Vec(0, -v1);
                if((step2 == 8)|| (step2 == 9))
                    theta -= 3.14/8;
                break;
            case 5:
                _stop_point = Vec(0.8,  v1);
                if((step2 == 0)|| (step2 == 1))
                    theta -= 3.14/8;
                if((step2 == 8)|| (step2 == 9))
                    theta += 3.14/8;
                break;
            case 6:
                _stop_point = Vec(0.8, 1);
                if((step2 == 0)|| (step2 == 1))
                    theta += 3.14/8;
                break;
            default:
                break;
        }
        anchor = anchor + (_stop_point - _start_point)*0.1;
        if(++step2 >= 10) {
            start_point = _stop_point;
            if(++step1 >= 7) {
                out = 1;
                step1 = 0;
            }
            step2 = 0;
        }
    }
    void rotate(){
        if (z>=0&&z<=10){
            theta+=0.1;
        }
        else if (z>10&&z<=20){
            theta-=0.1;
        }
        else {z = 0;}
        z++;
    }
    ~UFO();
private:
    Figure *ufo[4];
    Vec anchor;
    Vec start_point;
    float theta;
    int z;
};
//---------------------------------------------------------------------------------------------------------------------//
class Car : public Figure {
public:
    Car(const Vec &anchor, float theta, int slot);
    void draw(); // Draw out all its figures
    void move() {
        Vec _start_point(start_point);
        Vec _stop_point(0.8,1);
        float _start_theta;
        float _stop_theta;
        float v1, h1;
        //slot number 0~4
        if (slot/5 == 0) {
            v1 = -0.3;
            h1 = 0.56 + slot * 0.24;
        }
        //slot number 5~9
        else {
            v1 = 0.3;
            h1 = 0.56 + (slot - 5)*0.24;
        }
        switch(step1) {
            case 0:
                _stop_point = _start_point + Vec(0, (1 + v1));
                if((step2 == 8)|| (step2 == 9)) theta -= 3.14/8;
                break;
            case 1:
                _stop_point = _start_point + Vec(h1, 0);
                if((step2 == 0)|| (step2 == 1)) theta -= 3.14/8;
                break;
            case 2:
                _stop_point = _start_point + Vec(-0.24, 0);
                if((step2 == 8)|| (step2 == 9)) theta += 3.14/8;
                break;
            case 3:
                _stop_point = _start_point + Vec(0, v1);
                if((step2 == 0)|| (step2 == 1)) theta += 3.14/8;
                break;
            case 4:
                _stop_point = _start_point + Vec(0, -v1);
                if((step2 == 8)|| (step2 == 9)) theta -= 3.14/8;
                break;
            case 5:
                _stop_point = Vec(0.8,  v1);
                if((step2 == 0)|| (step2 == 1)) theta -= 3.14/8;
                if((step2 == 8)|| (step2 == 9)) theta += 3.14/8;
                break;
            case 6:
                _stop_point = Vec(0.8, 1);
                if((step2 == 0)|| (step2 == 1)) theta += 3.14/8;
                break;
            default:
                break;
        }
        anchor = anchor + (_stop_point - _start_point) * 0.1;
        if(++step2 >= 10) {
            start_point = _stop_point;
            if(++step1 >= 7) { out = 1; step1 = 0; }
            step2 = 0;
        }
    }
    ~Car();
private:
    Figure *car[4];
    Vec anchor;
    Vec start_point;
    float theta;
};
//---------------------------------------------------------------------------------------------------------------------//
class Spacecraft : public Figure{
public:
    double w=0.85;
    Spacecraft(const Vec &anchor, float theta, double w, int slot);
    void draw(); // Draw out all its figures
    void zoom();
    void move() {
        Vec _start_point(start_point);
        Vec _stop_point(0.8,1);
        float _start_theta;
        float _stop_theta;
        float v1, h1;
        if (slot/5 == 0){
            v1 = -0.3;
            h1 = 0.56 + slot * 0.24;
        }
        else {
            v1 = 0.3;
            h1 = 0.56 + (slot - 5)*0.24;
        }

        switch(step1) {
            case 0:
                _stop_point = _start_point + Vec(0, (1 + v1));
                if((step2 == 8)|| (step2 == 9))
                    theta -= 3.14/8;
                break;
            case 1:
                _stop_point = _start_point + Vec(h1, 0);
                if((step2 == 0)|| (step2 == 1))
                    theta -= 3.14/8;
                break;
            case 2:
                _stop_point = _start_point + Vec(-0.24, 0);
                if((step2 == 8)|| (step2 == 9))
                    theta += 3.14/8;
                break;
            case 3:
                _stop_point = _start_point + Vec(0, v1);
                if((step2 == 0)|| (step2 == 1))
                    theta += 3.14/8;
                break;
            case 4:
                _stop_point = _start_point + Vec(0, -v1);
                if((step2 == 8)|| (step2 == 9))
                    theta -= 3.14/8;
                break;
            case 5:
                _stop_point = Vec(0.8,  v1);
                if((step2 == 0)|| (step2 == 1))
                    theta -= 3.14/8;
                if((step2 == 8)|| (step2 == 9))
                    theta += 3.14/8;
                break;
            case 6:
                _stop_point = Vec(0.8, 1);
                if((step2 == 0)|| (step2 == 1))
                    theta += 3.14/8;
                break;
            default:
                break;
        }
        anchor = anchor + (_stop_point - _start_point) * 0.1;
        if(++step2 >= 10) {
            start_point = _stop_point;
            if(++step1 >= 7) {
                out = 1;
                step1 = 0;
            }
            step2 = 0;
        }

        //cout<<"slot="<<slot<<", step1:"<<step1<<", step2:"<<step2<<", w="<<w<<",theta="<<(theta/3.14*360)<<",x="<<anchor.getX()<<" y="<<anchor.getY()<<endl;
    }
    ~Spacecraft();
private:
    Figure *spacecraft[8];
    Vec anchor;
    Vec start_point;
    float theta;
};
//---------------------------------------------------------------------------------------------------------------------//
class Door : public Figure{
public:
    Door(const Vec &anchor);
    ~Door();
    void draw();
private:
    int a;
    Vec anchor;
    Figure *door;
    void setcolor(float *r, float *g, float *b);
};
#endif //H8_VEHICLES_H
