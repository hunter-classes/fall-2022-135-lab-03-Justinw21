/*
Author: Justin Wong
Course: CSCI-135
Instructor: Mr. Zamansky
Assignment: Lab 4 Task D
Takes two dates and prints the west basin and dates in reverse-chronological order
*/
#include <iostream>
#include "reservoir.h"
#include <climits>
#include <fstream>
#include <cstdlib>
#include <string.h>

void reverse_order(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading" << "\n";
        exit(1);
    }
    std::string junk;
    getline(fin, junk);
    std::string dates;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    double doubles[366];
    std::string datess[366];
    int size;
    bool inInterval = false;
    int i = 0;
    while(fin >> dates >> eastSt >> eastEl >> westSt >> westEl){
        if(dates == date1)
        {
            inInterval = true;
        }
        if(inInterval){
            datess[i] = dates;
            doubles[i] = westSt;
            size++;
            i++;
        }
        if(dates == date2)
            {
            inInterval = false;
            }
        fin.ignore(INT_MAX, '\n');
    };
    
    for(int i = size - 1; i >= 0; i--){
        std::cout << datess[i] << " ";
        std::cout << " " << doubles[i] << " billion gallons " << std::endl;
    }
    
}