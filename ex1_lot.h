//
// Created by delight on 2016/12/12.
//
#ifndef H8_EX1_LOT_H
#define H8_EX1_LOT_H
using namespace std;
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
// Parking lot will generate the arrival ticket and departure ticket
#define MAX_NUM_SPACE_PER_FLOOR	20
#define MIN_NUM_SPACE_PER_FLOOR	10
class ParkingSpace {
public:
    ParkingSpace(unsigned int _floor, unsigned int _number) {
        number = _number;
        floor  = _floor;
        status = false;
        cout<<"ParkingSpace constructor with <"<<floor<<", "<<number<<">."<<endl;
    }
    virtual ~ParkingSpace() {
        status = false;
        cout<<"ParkingSpace destructor with <"<<floor<<","<<number<<">"<<endl;
    }
    bool isFreeSpace() {
        if (status) {
            //cout << "The space is not free now, allocation failed" <<endl;
            return false;
        }
        cout<<"[ARRIVAL]:Find free parking space <"<<floor<<","<<number<<"> successfully."<<endl;
        status = true;
        return true;
    }
    bool FreeSpace() {
        if (!status) {
            cout << "The space is originally free now, wrong status" << endl;
            return false;
        }
        status = false;
        return true;
    }
    void print() { cout<<"<floor:"<<floor<<", number:"<<number<<endl; }
private:
    bool 					status; //free or not
    unsigned int			number; //parking seriers number in one floor
    unsigned int   		floor;  //floor number
};
class ParkingFloor {
public:
    ParkingFloor() {
        cout<<"Construct blank parking floor"<<endl;
        floor_ = 0xff; //0xff refer to invalid floor number
    }
    ParkingFloor(const unsigned int floor, const unsigned int number) {
        cout<<"Construct parking floor at<"<<floor<<"> with <"<<number<<"> parking space"<<endl;
        floor_ = floor;
        if(number <= MAX_NUM_SPACE_PER_FLOOR) {
            for(int i=0; i<number; i++) {
                ParkingSpace *space = new ParkingSpace(floor, i);
                packingfloor_.push_back(space);
                cout<<"push back the parking space to floor <"<<floor_<<">."<<endl;
            }
        }
        else {
            cout<<"Invalid number of parking space, no parking space in the floor."<<endl;
        }
    }
    ~ParkingFloor() {
        cout<<"Destruct parking floor at floor <"<<floor_<<">."<<endl;
        for ( vector<ParkingSpace *>::iterator it = packingfloor_.begin() ; it != packingfloor_.end() ; ++it ) {
            delete *it;
        }
        cout<<"Destruct parking floor at floor <"<<floor_<<"> successfully."<<endl;
    }
    // Find the free parking space in current floor/ /find free from 1st floor to 2nd floor, and so on
    ParkingSpace* findFreeParkingSpace() {
        int random_slot1 = rand();
        int random_slot = (unsigned int)(MIN_NUM_SPACE_PER_FLOOR  * ((float)random_slot1/(float) RAND_MAX));
        cout<<"Find free parking space from whole parking lot from "<<random_slot<<endl;
        // start from the random slot
        for ( vector<ParkingSpace *>::iterator it = packingfloor_.begin() + random_slot ; it != packingfloor_.end() ; ++it ) {
            ParkingSpace *space = *it;
            if(space->isFreeSpace()) {
                //cout<<"Find free parking space successfully."<<endl;
                return *it;
            }
        }
        for ( vector<ParkingSpace *>::iterator it = packingfloor_.begin() ; it != packingfloor_.end() ; ++it ) {
            ParkingSpace *space = *it;
            if(space->isFreeSpace()) {
                return *it;
            }
        }
        cout<<"ERROR:Find free parking space failed."<<endl;
        return NULL;
    }
    int getfloor() { return floor_; }
private:
    vector<ParkingSpace *> 	packingfloor_;
    unsigned int   		floor_;  //floor number
};
class ParkingLot {
public:
    void insertPartkingFloor(const unsigned int floor, ParkingFloor *parkingfloor) {
        for ( vector<ParkingFloor *>::iterator it = parkinglot_.begin() ; it != parkinglot_.end() ; ++it ) {
            ParkingFloor *floor1 = *it;
            if(floor == floor1->getfloor()) {
                cout<<"The parking floor<"<<floor<<"> exist, insert failed."<<endl;
                return;
            }
        }
        parkinglot_.push_back(parkingfloor);
        cout<<"Insert parking floor<"<<floor<<"> successfully."<<endl;
    }
    // find free from 1st floor to 2nd floor, and so on
    ParkingSpace* findFreeParkingSpace() {
        ParkingSpace *p1;
        //cout<<"Find free parking space from whole parking lot."<<endl;
        for ( vector<ParkingFloor *>::iterator it = parkinglot_.begin() ; it != parkinglot_.end() ; ++it ) {
            ParkingFloor *floor = *it;
            if((p1 = floor->findFreeParkingSpace())!= NULL) {
                return p1;
            }
        }
        cout<<"ERROR: no free parking space found!"<<endl;
        return NULL;
    }
    void freeParkingSpace(ParkingSpace* space) {
        if(space == NULL)
            cout<<"NULL parking space, nothing done."<<endl;
        space->FreeSpace();
    }
    void vehicleArrival(unsigned int time) {}
    vector<ParkingFloor *> parkinglot_;
    ParkingLot() {}
    ~ParkingLot() {
            if (!parkinglot_.empty()) {
                for (vector<ParkingFloor *>::iterator it = parkinglot_.begin(); it != parkinglot_.end(); ++it) {
                    delete *it;
                    cout << "Removing parking floor one by one." << endl;
                }
                cout << "ParkingLot::deleteInstance." << endl;
            }
    }
};
#endif //H8_EX1_LOT_H
