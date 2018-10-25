//
//  main.cpp
//  hmw_3_1
//
//  Created by Gaurav Gulati on 10/23/18.
//  Copyright © 2018 Gaurav Gulati. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

bool checkFile(const char* fileName){
    ifstream check(fileName);
    if(check){
        return true;
    }
    return false;
}

int main() {
    string input;
    cout << "Enter a file name: ";
    getline(cin, input);
    
    
    bool fileExists = checkFile(input.c_str());
    
    while(fileExists){
        
        ifstream ifs;
        ifs.open(input.c_str());
        // get number of characters
        ifs.seekg(0, fstream::end);
        long numOfChars = ifs.tellg();
        cout << "Number of characters = " << numOfChars << endl;
        // get number of words
        ifs.seekg(0, fstream::beg);
        string word;
        int wordCount = 0;
        while(ifs >> word){
            wordCount++;
        }
        // double check to make sure line 45 works in visual studios
            // (does it clear the buffer?
        ifs.clear();
        cout << "Number of words      = " << wordCount << endl;
        //get number of lines
        ifs.seekg(0, fstream::beg);
        string line;
        int numOflines = 0;
        while(getline(ifs, line)){
            numOflines++;
        }
        cout << "Number of lines      =  " << numOflines << endl;
        // get new file
        ifs.close();
        cout << "Enter a file name: ";
        getline(cin, input);
        fileExists = checkFile(input.c_str());
    }
    cout << "File " << input << " does not exist! Exit." << endl;
    return 0;
    
}
