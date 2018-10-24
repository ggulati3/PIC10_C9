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

string reverseLine(string line){
    string str = "";
    for(long i = line.length()-1; i >= 0; i--){
        str += line[i];
    }
    return str;
}

int main() {
    string input;
    vector<string> lines;
    cout << "Enter a file name: " ;
    cin >> input;
    const char * fileName = input.c_str();
    bool check = checkFile(fileName);
    while(check){
        fstream ifs;
        ifs.open(fileName, fstream::in);
        string line;
        cout << "Original file " << input << " content:" << endl;
        while(getline(ifs,line)){
            lines.push_back(line);
        }
        for(int i = 0; i < lines.size(); i++){
            cout << lines[i] << endl;
            lines[i] = reverseLine(lines[i]);
        }
        ifs.close();
        
        ofstream ofs;
        ofs.open(fileName, ofstream::out | ofstream::trunc);
        for(int i = 0; i < lines.size(); i++){
            ofs << lines[i] << endl;
        }
        
        ofs.close();
        
        cout << "Enter a file name: " ;
        cin >> input;
        check = checkFile(input.c_str());
    }
    
    
    return 0;
}
