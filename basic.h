//
// Created by delight on 2016/12/12.
//
#ifndef H8_BASIC_H
#define H8_BASIC_H
#include <math.h>
//---------------------------------------------------------------------------------------------------------------------//
class Vec {
public:
    float x,y;
//constructor
    Vec(float _x, float _y) { x = _x; y = _y; }
    //Vec(Vec& _v) { x = _v.x; y = _v.y; }

    float getX() {return x;}
    float getY() {return y;}
//Overloads + operator, returns the sum of 2 Vec
    Vec operator+ (Vec v) {
        return Vec(x + v.getX(), y + v.getY());
    }
//Overloads - operator, returns the sum of 2 Vec
    Vec operator- (Vec v) {
        return Vec(x - v.getX(), y - v.getY());
    }
//Overload * operator on a float k, return current Vector scaled by k
    Vec operator* (float k) {
        return Vec(x * k, y * k);
    }
//Overload << on an angle, return current vector rotated counter clockwise, by this angle
    Vec operator<< (float theta) {
        return Vec( x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    }
//Overload >> on an angle, return current vector rotated counter clockwise, by this angle
    Vec operator>> (float theta) {
        return Vec( x * cos(-theta) - y * sin(-theta), x * sin(-theta) + y * cos(-theta));
    }
};
//---------------------------------------------------------------------------------------------------------------------//
class Figure {
protected:
    Vec anchor;
    float theta;
    float r,g,b;
public:
    Figure() : anchor(0, 0)
    {
        slot = 0;
        out = 0;    // Now vehicle is in
        step1 = 0;  //Maximum step 7, step
        step2 = 0;
    }
    Vec getAnchor() {return anchor;}

    void setSlot(int slot_) {slot = slot_;}

    int getOut() {return out;}

    void setAnchor(Vec a) {anchor = a;}
    virtual void draw() = 0;

    virtual ~Figure() {}

    int slot;
    int out;
    int step1;
    int step2;
};
//---------------------------------------------------------------------------------------------------------------------//
class Rect:public Figure{
public:
    Rect(Vec anchor, Vec dia1, Vec dia2, Vec dia3, Vec dia4, float r, float g, float b);
    void draw();
private:
    Vec anchor;
    Vec dia1,dia2,dia3,dia4;
    float r,g,b;
};
//---------------------------------------------------------------------------------------------------------------------//
class Trian:public Figure{
public:
    Trian(Vec anchor, Vec vec1, Vec vec2, Vec vec3, float r, float g, float b);
    void draw();
private:
    Vec anchor;
    Vec vec1, vec2, vec3;
    float r,g,b;
};
//---------------------------------------------------------------------------------------------------------------------//
class Circle:public Figure{
public:
    Circle(Vec anchor);
    void draw();
private:
    Vec anchor;
    double R;
    float r,g,b;
};
//---------------------------------------------------------------------------------------------------------------------//
class HalfCir:public Figure{
public:
    HalfCir(Vec anchor, float theta);
    void draw();
private:
    Vec anchor;
    float theta;
    double R;
    float r,g,b;
};
//---------------------------------------------------------------------------------------------------------------------//
class Line:public Figure{
public:
    Line(Vec anchor, float theta);
    void draw();
private:
    float theta;
    Vec anchor;
    Vec vec1 = { 0.08/2, sqrt(3)*0.08/2 };
    Vec vec2 = { -0.08/2, sqrt(3)*0.08/2 };
    float r,g,b;
};
//---------------------------------------------------------------------------------------------------------------------//
class Trapezium:public Figure{
public:
    Trapezium(Vec anchor, Vec vec1, Vec vec2, Vec vec3, Vec vec4, float r, float g, float b);
    void draw();
private:
    Vec anchor;
    Vec vec1,vec2,vec3,vec4;
    float r,g,b;
};
#endif //H8_BASIC_H
