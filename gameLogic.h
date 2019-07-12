//
// Created by dzirt on 7/6/2019.
//

#ifndef UNTITLED2_GAMELOGIC_H
#define UNTITLED2_GAMELOGIC_H

#include <iostream>
#include <string>

#include <stdio.h>
#include <cstdlib>

#include <chrono>
#include <thread>

using namespace std;

class gameLogic {

public:



static const size_t row=4;
static const size_t columns=4;

    //prototypes

    void Start();
    void coutArr(char(*)[columns]); //! C++ requires that we specify the number of columns in the function definition
    void PrintTable(char(*)[columns]);
    void WinnerDetect(char(*)[columns]);//or we can leave it like that, without declaration by pointer
    void GameOver();



};



#endif //UNTITLED2_GAMELOGIC_H
