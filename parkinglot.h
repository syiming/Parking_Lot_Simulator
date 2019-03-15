//
// Created by delight on 2016/12/12.
//

#ifndef H8_PARKINGLOT_H
#define H8_PARKINGLOT_H
#include <iostream>
#include "Vehicles.h"
#include <ctime>
#include <cstdlib>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------//
class parkinglot{
public:
    static parkinglot* getInstance(){
        static parkinglot *s = NULL;
        if (s == NULL) {
            s = new parkinglot();
        }
        return s;
    }
    static void deleteInstance() {
        parkinglot *s = parkinglot::getInstance();
        if (s != NULL) delete s;
        s = NULL;
    }
    virtual void draw();
    void vehin(int slot_num, int type);
    void vehout();
private:
    Figure *slot[10] = {NULL};
    parkinglot(){
        int number,r;
        srand(time(0));
        number = rand();
        number = number % 3+1;
        cout<<"number="<<number<<endl;
        for (int i = 0; i<number; i++){
            r = rand() % 10;
            cout<<"r="<<r<<endl;
            if (slot[r]==NULL){
                slot[r] = new Door((Vec){(r%5-2)*0.24,((r/5)*2-1)*0.58});
            }
        }
    };
    ~parkinglot(){};
};

#endif //H8_PARKINGLOT_H
