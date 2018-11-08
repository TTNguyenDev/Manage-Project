//
//  ROOM.hpp
//  Mange Project
//
//  Created by TT Nguyen on 7/28/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#ifndef ROOM_hpp
#define ROOM_hpp

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class House {
    
private:
    
    double ConstRecieve = 10900000;
    
public:
    
    void inputFromFile(string path, string path1);
    void exportToCustomers(string path);
    void exportMangeMoney();
    
};


class Room {
    
private:
    
    string name;
    string room;
    string water;
    string elec;
    int waterUsed;
    int elecUsed;
    int const elecFees = 3300;
    int const waterFees = 5000;
    int const garbage = 13000;
    double sum;
    
public:
    
    void getRoomValue();
    friend istream& operator>>(istream& stream, Room& r);
    friend void House::exportToCustomers(string path);
    friend void exportMangeMoney();
    void calculate(int i);
    double getSumOfMonth();
    
    string getTotalElec();
    string getTotalWater();
    
};





#endif /* ROOM_hpp */
