//
//  ROOM.cpp
//  Mange Project
//
//  Created by TT Nguyen on 7/28/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "ROOM.hpp"
#include <iomanip>
#include <sstream>

vector <Room> thisMonth;
vector <Room> preMonth;

void Room::getRoomValue() {
    
    string value[6] = {"1700000", "2000000", "2000000", "1400000", "2000000", "2000000"};
    
    for (int i = 0; i < thisMonth.size(); i++) {
        thisMonth[i].room = value[i];
        
    }
}

void Room::calculate(int i) {
    
    thisMonth[i].elecUsed = stoi(thisMonth[i].elec) - stoi(preMonth[i].elec);
    thisMonth[i].waterUsed = stoi(thisMonth[i].water) - stoi(preMonth[i].water);
    
    thisMonth[i].sum = thisMonth[i].elecUsed * elecFees + thisMonth[i].waterUsed * waterFees + stod(thisMonth[i].room) + garbage;
    
}

double Room::getSumOfMonth() {
    
    double sum = 0;
    
    for (int i = 0; i < thisMonth.size(); i++)
        sum += thisMonth[i].sum;
    
    return sum;
    
}
istream& operator >> (istream& stream, Room& r) {
    
    getline(stream, r.name, ',');
    getline(stream, r.elec, ',');
    getline(stream, r.water, '\n');
    
    return stream;
    
}

void House::exportToCustomers(string path) {
    
    ofstream f(path);
    thisMonth[1].getRoomValue();
    for (int i = 0; i < thisMonth.size(); i++) {
        thisMonth[i].calculate(i);
        
        f << "\t\t\t\t*** PHIEU THU TIEN " << thisMonth[i].name << " ***" << endl;
        f << "\t\t\t\t  ---------------$$$--------------" << endl;
        f << "\t\t\t - Tien phong la  : " << thisMonth[i].room << endl;
        
        f << "\t\t\t - So dien        : " << endl;
        f << "\t\t\t   + So cu        : " << preMonth[i].elec << endl;
        f << "\t\t\t   + So moi       : " << thisMonth[i].elec << endl;
        f << "\t\t\t   + Tieu thu     : " << thisMonth[i].elecUsed << endl;
        f << "\t\t\t   + Tong         : " << thisMonth[i].elecUsed << " x " << thisMonth[i].elecFees << " = " <<  thisMonth[i].elecUsed * thisMonth[i].elecFees << endl;
        
        f << "\t\t\t - So nuoc        : " << endl;
        f << "\t\t\t   + So cu        : " << preMonth[i].water << endl;
        f << "\t\t\t   + So moi       : " << thisMonth[i].water << endl;
        f << "\t\t\t   + Tieu thu     : " << thisMonth[i].waterUsed << endl;
        f << "\t\t\t   + Tong         : " << thisMonth[i].waterUsed << " x " << thisMonth[i].waterFees << " = " <<thisMonth[i].waterUsed * thisMonth[i].waterFees << endl;
        f << "\t\t\t - Tien rac       : " << thisMonth[i].garbage <<  endl;
        f << "\t\t\t - Tong Cong      : " << to_string(thisMonth[i].sum) << endl;
        f << "\t\t\t - GHI CHU        : " << endl;
        f << "\t\t\t   + Tien Dien 3300/kw. " << endl;
        f << "\t\t\t   + Tien Nuoc 5000/khoi. " << endl << endl << endl << endl;
        
    }
    
    f.close();
    
}


void House::inputFromFile(string path, string path1) {
    
    ifstream now_f(path);
    ifstream pre_f(path1);
    
    Room temp;
    
    now_f.seekg(16, ios_base::cur);
    pre_f.seekg(16, ios_base::cur);
    
    while (!now_f.eof() && !pre_f.eof()){
        now_f >> temp;
        thisMonth.push_back(temp);
        pre_f >> temp;
        preMonth.push_back(temp);
    }
    
    now_f.close();
    pre_f.close();
    
}

string Room::getTotalElec() {
    int sum = 0;
    for (int i = 0; i < thisMonth.size(); i++)
        sum += thisMonth[i].elecUsed;
    return to_string(sum*elecFees);
}

string Room::getTotalWater() {
    int sum = 0;
    for (int i = 0; i < thisMonth.size(); i++)
        sum += thisMonth[i].waterUsed;
    return to_string(sum*waterFees);
}

void House::exportMangeMoney() {
    
    cout << "\t\t\t\t***************************************" << endl;
    cout << "\t\t\t\t\t\t **** BANG BAO CAO **** " << endl << endl;
    cout << "\t\t\t\t - Tong tien thu duoc : " << to_string(thisMonth[1].getSumOfMonth()) << endl << endl;
    cout << "\t\t\t\t - Tien hang thang    : " << to_string(ConstRecieve) << endl << endl;
    cout << "\t\t\t\t - Tien Dien Nuoc     : " << to_string(stod(thisMonth[1].getTotalElec()) + stod(thisMonth[1].getTotalWater())) << endl;
    cout << "\t\t\t\t    + Tien Dien       : " << thisMonth[1].getTotalElec() << endl;
    cout << "\t\t\t\t    + Tien Nuoc       : " << thisMonth[1].getTotalWater() << endl;
    cout << "\t\t\t\t***************************************\n\n" << endl;
    
}


