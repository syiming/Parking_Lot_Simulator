//
// Created by delight on 2016/12/12.
//
#ifndef H8_EX1_H
#define H8_EX1_H
using namespace std;
#include <iostream>
#include "ex1_lot.h"
typedef enum PRICE_PER_HOUR_BY_TYPR {
    PRICE_FOR_BIKE 		= 2,
    PRICE_FOR_MOTOBIKE 	= 3,
    PRICE_FOR_CAR 		= 5,
    PRICE_FOR_VAN 		= 8
}PricePerHour;

class Vehicles {
public:
    Vehicles(PricePerHour price) {
        cout<<"Construct Vehicles."<<endl;
        price_ = price;
        arrival_ = 0;
        departure_ = 0;
    }
    virtual ~Vehicles() {
        cout<<"Destruct Vehicles."<<endl;
    }
    virtual void print() {
        cout<<"Vehicles type."<<endl;
    }
    PricePerHour getPricePerHour() {
        cout<<"price per hour is "<<price_<<endl;
        return price_;
    }
    virtual bool arrival(ParkingLot *lot, unsigned int arrival){
        cout<<"[ARRIVAL]:Vehicle type arrival to parking lot at <"<<arrival<<">."<<endl;
        arrival_ = arrival;
        if(lot != NULL) {
            //cout<<"find free parking space for Vehicle."<<endl;
            if((space_ = lot->findFreeParkingSpace()) != NULL) {
                //cout<<"Find free parking space for vehicle."<<endl;
                return true;
            }
        }
        cout<<"ERROR:Can't find free parking space for vehicle."<<endl;
        return false;
    }
    //departure time
    virtual void departure(ParkingLot *lot, unsigned int departure) {
        cout<<"[DEPARTURE}: Vehicle type departure to parking lot at <"<<departure<<">."<<endl;
        departure_ = departure;
        if(space_ != NULL) {
            //cout<<"Free parking space for Vehicle."<<endl;
            space_->FreeSpace();
        }
        else
            cout<<"ERROR: wrong parking space when vehicle departure."<<endl;
        printPrice();
    }

    void printPrice() {
        cout<<"[DEPARTURE]: duration is <"<<(departure_ - arrival_)<<"> hours,parking price is <"<<(departure_ - arrival_) * (unsigned int)price_<<">."<<endl;
    }
#if 0
    int getArrivalTime(){
		int arrivalTime;
		arrivalTime = arrival_->getArrivalTime();
		cout<<"Arrival time is "<<arrivalTime<<endl;
		return arrivalTime;
	}
#endif
    int	arrival_;
    int departure_;
    ParkingSpace *space_;
private:
    PricePerHour price_;  		//price per hour
};

class Van: public Vehicles {
public:
    Van():Vehicles(PRICE_FOR_VAN) {
        cout<<"Construct Van."<<endl;
    }

    ~Van() {
        cout<<"Destruct Van."<<endl;
    }

    virtual void print() {
        cout<<"Van type."<<endl;
    }
    //arrival time
    bool arrival(ParkingLot *lot,unsigned  int arrival) {
        cout << "[ARRIVAL]:VAN type of vihicle arrival to parking lot at <" << arrival << "> clock." << endl;
        arrival_ = arrival;
        if (lot != NULL) {
            if ((space_ = lot->findFreeParkingSpace()) != NULL) {
                return true;
            }
        }
        cout << "ERROR:Can't find free parking space for Van." << endl;
        return false;
    }
    //departure time
    void departure(ParkingLot *lot, int departure) {
        cout<<"[DEPARTURE}: Van type of vehicle departure to parking lot at <"<<departure<<">."<<endl;
        departure_ = departure;
        if(space_ != NULL) {
            space_->FreeSpace();
        }
        else
            cout<<"ERROR: wrong parking space when Van departure."<<endl;
        printPrice();
    }
};

class CAR: public Vehicles {
public:
    CAR():Vehicles(PRICE_FOR_CAR) {
        cout<<"Construct Car."<<endl;
    }
    ~CAR() {
        cout<<"Destruct Car."<<endl;
    }
    virtual void print() {
        cout<<"Car type."<<endl;
    }//arrival time
    bool arrival(ParkingLot *lot, unsigned int arrival) {
        cout << "[ARRIVAL]:CAR type of vihicle arrival to parking lot at <" << arrival << "> clock." << endl;
        arrival_ = arrival;
        if (lot != NULL) {
            if ((space_ = lot->findFreeParkingSpace()) != NULL) {
                return true;
            }
        }
        cout << "ERROR:Can't find free parking space for Car." << endl;
        return false;
    }
    //departure time
    void departure(ParkingLot *lot, unsigned int departure) {
        cout<<"[DEPARTURE}: CAR type of vehicle departure to parking lot at <"<<departure<<">."<<endl;
        departure_ = departure;
        if(space_ != NULL) {
            space_->FreeSpace();
        }
        else
            cout<<"ERROR: wrong parking space when Car departure."<<endl;
        printPrice();
    }
};

class Motobike: public Vehicles {
public:
    Motobike():Vehicles(PRICE_FOR_MOTOBIKE) {
        cout<<"Construct Motobike."<<endl;
    }
    ~Motobike() {
        cout<<"Destruct Motobike."<<endl;
    }

    virtual void print() {
        cout<<"Motobike type."<<endl;
    }
    //arrival time
    bool arrival(ParkingLot *lot, unsigned int arrival) {
        cout<<"[ARRIVAL]:MOTOBIKE type of vihicle arrival to parking lot at <"<<arrival<<"> clock."<<endl;
        arrival_ = arrival;
        if(lot != NULL) {
            if((space_ = lot->findFreeParkingSpace()) != NULL) {
                return true;
            }
        }
        cout<<"ERROR:Can't find free parking space for Motobike."<<endl;
        return false;
    }
//departure time
    void departure(ParkingLot *lot, unsigned int departure) {
        cout<<"[DEPARTURE}: MOTOBIKE type of vehicle departure to parking lot at <"<<departure<<">."<<endl;
        departure_ = departure;
        if(space_ != NULL) {
            space_->FreeSpace();
        }
        else
            cout<<"ERROR: wrong parking space when Motobike departure."<<endl;
        printPrice();
    }
};

class Bicycle: public Vehicles {
public:
    Bicycle():Vehicles(PRICE_FOR_BIKE) {
        cout<<"Construct Bicycle."<<endl;
    }
    ~Bicycle() {
        cout<<"Destruct Bicycle."<<endl;
    }
    virtual void print() {
        cout<<"Bicycle type."<<endl;
    }	//arrival time
    bool arrival(ParkingLot *lot, unsigned int arrival) {
        cout<<"[ARRIVAL]:BICYCLE type of vihicle arrival to parking lot at <"<<arrival<<"> clock."<<endl;
        arrival_ = arrival;
        if(lot != NULL) {
            if((space_ = lot->findFreeParkingSpace()) != NULL) {
                return true;
            }
        }
        cout<<"ERROR:Can't find free parking space for Bicycle."<<endl;
        return false;
    }
//departure time
    void departure(ParkingLot *lot, unsigned int departure) {
        cout<<"[DEPARTURE}: BICYCLE type of vehicle departure to parking lot at <"<<departure<<">."<<endl;
        departure_ = departure;
        if(space_ != NULL) {
            space_->FreeSpace();
        }
        else
            cout<<"ERROR: wrong parking space when Bicycle departure."<<endl;
        printPrice();
    }
};

#endif //H8_EX1_H
