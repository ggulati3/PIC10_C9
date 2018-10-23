//
//  main.cpp
//  hmw_3_3
//
//  Created by Gaurav Gulati on 10/23/18.
//  Copyright © 2018 Gaurav Gulati. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

bool checkFile(const char *s){
    fstream check(s);
    return (bool)check;
}

vector<string> reverseList(fstream& ifs, const char* fileName){
    vector<string> reverseList;
    
    ifs.seekg(0, ifstream::beg);
    string line;
    while(getline(ifs, line)){
        istringstream iss(line);
        cout << line; 
    }
              
    return reverseList;
    
}

int main() {
    string input;
    cout << "Enter a file name: " ;
    cin >> input;
    const char * fileName = input.c_str();
    bool check = checkFile(fileName);
    while(check){
        fstream ifs;
        ofstream ofs;
        ifs.open(fileName, fstream::in);
        
        reverseList(ifs, fileName);
        
        ifs.close();
        ofs.close();
        cout << "Enter a file name: " ;
        cin >> input;
        check = checkFile(input.c_str());
    }
    
    
    return 0;
}
