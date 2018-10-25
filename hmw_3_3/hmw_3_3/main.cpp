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
    cout << "Enter the name of the file: " ;
    cin >> input;
    cout << endl;
    
    const char * fileName = input.c_str();
    bool check = checkFile(fileName);
    if(!check){
        cerr << "Error: " << strerror(errno);
    }
    fstream ifs;
    ifs.open(fileName, fstream::in);
    string line;
    cout << "Original file " << input << " content:" << endl;
    while(getline(ifs,line)){
        cout << line << endl;
        lines.push_back(line);
    }
    cout << endl;
    ifs.close();
    
    ofstream ofs;
    ofs.open(fileName, ofstream::out | ofstream::trunc);
    cout << "Reversed files " << input << " content:" << endl;
    for(int i = 0; i < lines.size(); i++){
        lines[i] = reverseLine(lines[i]);
        cout << lines[i] << endl;
        ofs << lines[i] << endl;
    }


    ofs.close();


    
    
    return 0;
}
