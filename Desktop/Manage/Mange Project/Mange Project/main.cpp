//
//  main.cpp
//  Mange Project
//
//  Created by TT Nguyen on 7/28/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "ROOM.hpp"

int main() {
    
    string _newString, _preString;
    string str = "/Users/trietnguyen/Desktop/Manage/DataBase/";
    
    cout << "Enter DataBase Of This Month: \n";
    fflush(stdin);
    cin >> _newString;
    
    
    cout << "Enter DataBase Of Previous Month: \n";
    fflush(stdin);
    cin >> _preString;
    
    House a;
    a.inputFromFile(str + _newString + ".csv" , str + _preString + ".csv");
    a.exportToCustomers("/Users/trietnguyen/Desktop/Manage/ExportedData/" + _newString + ".doc");
    a.exportMangeMoney();
    
}
