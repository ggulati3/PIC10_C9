//
//  main.cpp
//  hmw_3_2
//
//  Created by Gaurav Gulati on 10/23/18.
//  Copyright © 2018 Gaurav Gulati. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

bool isEmpty(ifstream& ifs){
    ifs.seekg(0, fstream::end);
    if(ifs.tellg() == 0){
        return true;
    }
    return false;
}

int main() {
    ifstream db;
    db.open("database.txt", ifstream::in);
    if(isEmpty(db)){
        cout << "The database database.txt is empty. Exit!" << endl;
        return 0;
    }
    cout << "hi";
    db.close();
    return 0;
}
