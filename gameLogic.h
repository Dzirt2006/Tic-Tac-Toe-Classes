//
// Created by dzirt on 7/6/2019.
//

#ifndef UNTITLED2_GAMELOGIC_H
#define UNTITLED2_GAMELOGIC_H

#include <iostream>

#include <stdio.h>
#include <cstdlib>

#include <chrono>
#include <thread>

using namespace std;

class gameLogic {

public:



    //array size dimmension
    int row;
    int column;




    //prototypes

    void Start();
    void coutArr(char[][9]); //! C++ requires that we specify the number of columns in the function definition
    void PrintTable(char[][9]);
    void WinnerDetect(char[][9]);
    int CheckXOFirst(char);
    void GameOver();





};



#endif //UNTITLED2_GAMELOGIC_H
