//
//  main.cpp
//  hmw_3_2
//
//  Created by Gaurav Gulati on 10/23/18.
//  Copyright © 2018 Gaurav Gulati. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool isEmpty(ifstream& ifs){
    ifs.seekg(0, fstream::end);
    if(ifs.tellg() == 0){
        return true;
    }
    ifs.seekg(0, fstream::beg);
    return false;
}

int countLines(ifstream& ifs){
    string line;
    int count = 0;
    ifs.seekg(0, ifstream::beg);
    while(getline(ifs, line)){
        count++;
    }
    ifs.clear();
    ifs.close();
    return count;
}

void printTemp(){
    ifstream temp;
    temp.open("template.txt");
    cout << "Template content:" << endl;
    string tempLine;
    while(getline(temp, tempLine)){
        cout << tempLine << endl;
    }
    cout << endl;
    temp.close();
}

void printJunkLetter(int num, vector<string> words){
    ifstream ifs;
    ifs.open("template.txt");
    string line;
    while(getline(ifs, line)){
        line.replace(line.find("|1|"), 3, words[0]);
        line.replace(line.find("|2|"), 3, words[1]);
        line.replace(line.find("|3|"), 3, words[2]);
        line.replace(line.find("|4|"), 3, words[3]);
        line.replace(line.find("|5|"), 3, words[4]);
        line.replace(line.find("|6|"), 3, words[5]);
        line.replace(line.find("|7|"), 3, words[6]);
        line.replace(line.find("|1|"), 3, words[0]);
        line.replace(line.find("|3|"), 3, words[2]);
        line.replace(line.find("|3|"), 3, words[2]);
        cout << line << endl;
        line.clear();
    }
    ifs.close();
}

int main() {
    // open up database --> check if db is empty --> if not, then print db --> close db
    ifstream db;
    db.open("database.txt");
    int numOflines = 0;
    if(db.fail() || isEmpty(db)){
        cout << "The database database.txt is empty. Exit!" << endl;
        return 0;
    }
    else {
        string line;
        cout << "Database content:" << endl;
        while(!db.eof()) {
            getline(db, line);
            numOflines++;
            cout << line << endl;
        }
        cout << endl;
        db.close();
    }
    
    // open up template --> print tempalte --> close template
    printTemp();
    
    // get lines of template and separate by word
    ifstream ifs;
    ifs.open("database.txt");
    string data;
    int count = 0;
    while(getline(ifs, data)){
        istringstream istr(data);
        string word;

        vector<string> words;
        while(getline(istr, word, '|')){
            words.push_back(word);
            if(words.size() == 7){
                cout << "Junk letter for Record " << count << endl;
                count++;
                printJunkLetter(0, words);
                words.clear();
                cout << endl;
            }
        }
    }
    ifs.close();
    
    
    return 0;
}
