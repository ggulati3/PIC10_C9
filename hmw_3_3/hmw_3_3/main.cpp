////
//  main.cpp
//  hmw_3_3
//
//  Created by Gaurav Gulati on 10/23/18.
//  Copyright � 2018 Gaurav Gulati. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


string reverseLine(string line) {
    string str = "";
    for (long i = line.length() - 1; i >= 0; i--) {
        str += line[i];
    }
    return str;
}


int main() {
    string input;
    vector<string> lines;
    cout << "Enter the name of the file: ";
    cin >> input;
    
    ifstream ifs;
    const char * fileName = input.c_str();
    ifs.open(fileName, fstream::in);
    ifs.seekg(0, ifstream::end);
    if (ifs.fail() || !ifs.tellg()) {
        cout << "Error opening file " <<  input << "!" << endl;
        return 0;
    }
    else {
        ifs.seekg(0, ifstream::beg);
        cout << endl;
        string line;
        cout << "Original file " << input << " content:" << endl;
        while (getline(ifs, line)) {
            cout << line << endl;
            lines.push_back(line);
        }
        cout << endl;
        ifs.close();
        
        ofstream ofs;
        ofs.open(fileName, ofstream::out | ofstream::trunc);
        cout << "Reversed file " << input << " content:" << endl;
        for (int i = 0; i < lines.size(); i++) {
            lines[i] = reverseLine(lines[i]);
            cout << lines[i] << endl;
            ofs << lines[i] << endl;
        }
        
        
        ofs.close();
    }
    
    
    
    return 0;
}

