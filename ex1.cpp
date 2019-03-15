//
// Created by delight on 2016/12/12.
//
using namespace std;
#include <iostream>
#include "ex1.h"
#include "ex1_lot.h"
// To simplicity the code, only consider the hour for entry and exit
void ex1() {
    cout<<"-------------------- CREATE PARKING LOT START ----------------------"<<endl;
    ParkingLot *partkinglot = new ParkingLot();
    cout<<"construct singleton parking lot successfully."<<endl;
    // Insert parking floor for 1st floor with 10 parking space
    ParkingFloor *p1 = new ParkingFloor(1,10);
    partkinglot->insertPartkingFloor(1, p1);
    cout<<"Insert 1st parking floor successfully."<<endl;
    // Insert parking floor for 2nd floor with 15 parking space
    ParkingFloor *p2 = new ParkingFloor(2,15);
    partkinglot->insertPartkingFloor(2, p2);
    cout<<"Insert 2nd parking floor successfully."<<endl;
    cout<<"-------------------- CREATE PARKING LOT END ----------------------"<<endl;
    int rand_in = rand()%25+1;
    Vehicles *vehicles[rand_in];
    for (int i = 0; i<rand_in; i++){
        int type = rand()%4+1;
        switch (type) {
            case 1:
                vehicles[i] = new CAR();
                break;
            case 2:
                vehicles[i] = new Van();
                break;
            case 3:
                vehicles[i] = new Motobike();
                break;
            case 4:
                vehicles[i] = new Bicycle();
        }
    }
    int time;
    for (int i = 0; i<rand_in; i++) {
        time = rand()%10;
        cout << "******** ARRIVAL **********" << endl;
        vehicles[i]->arrival(partkinglot, time);
        cout << "******** ARRIVAL **********" << endl;
    }
    cout<<"----------------------------------------------"<<endl;
    for (int i = 0; i<rand_in; i++) {
        time = rand()%10+10;
        cout << "******** DEPARTURE **********" << endl;
        vehicles[i]->departure(partkinglot, time);
        cout << "******** DEPARTURE **********" << endl;
    }
    for (int i = 0; i<rand_in; i++) {delete vehicles[i];}
    //  construct the singleton instance for parking slot
    cout<<"-------------------- DELETE PARKING LOT START ----------------------"<<endl;
    delete partkinglot;
    cout<<"destruct singleton parking lot successfully."<<endl;
    cout<<"-------------------- DELETE PARKING LOT END ----------------------"<<endl;
}

