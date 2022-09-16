/*
Author: Justin Wong
Course: CSCI-135
Instructor: Mr. Zamansky
Assignment: Lab 4 Task A,B,C

Task A - Gets east storage based on date
Task B - Grabs the minimum and maximum of the east storage
Task C - Takes a date and sees if the east storage or west storage was larger during that day
*/
#include <iostream>
#include "reservoir.h"
#include <climits>
#include <fstream>
#include <cstdlib>
#include <string.h>

double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading" << "\n";
        exit(1);
    }
    std::string junk;
    getline(fin, junk);
    std::string date1;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl){
        if(date == date1){
            std::cout << eastSt << " billion gallons" << std::endl;
        }
        fin.ignore(INT_MAX, '\n');
    };
    return 0.0;
}
double get_min_east(){
std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading" << "\n";
        exit(1);
    }
    std::string junk;
    getline(fin, junk);
    std::string date1;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    double max = INT_MAX;
    while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl){
        fin.ignore(INT_MAX, '\n');
        if(eastSt < max){
            max = eastSt;
        }
    };
    std::cout << max << " billion gallons (min)" << std::endl;
    return 0.0;
}
double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading" << "\n";
        exit(1);
    }
    std::string junk;
    getline(fin, junk);
    std::string date1;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    double min = INT_MIN;
    while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl){
        fin.ignore(INT_MAX, '\n');
        if(eastSt > min){
            min = eastSt;
        }
    };
    std::cout << min << " billion gallons (max)" << std::endl;
    return 0.0;
}

std::string compare_basins(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()){
        std::cerr << "File cannot be opened for reading" << "\n";
        exit(1);
    }
    std::string junk;
    getline(fin, junk);
    std::string date1;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    while(fin >> date1 >> eastSt >> eastEl >> westSt >> westEl){
        if(date == date1){
            if(eastSt > westSt){
                std::cout << eastSt << " billion gallons(east)" << std::endl;
            }else if(westSt > eastSt){
                std::cout << westSt << "(west)" << std::endl;
            }else{
                std::cout << "Equal" << std::endl;
            }
        }
        fin.ignore(INT_MAX, '\n');
    };
    return "string"; 
}

