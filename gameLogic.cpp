//
// Created by dzirt on 7/6/2019.
//

#include "gameLogic.h"


void gameLogic::Start() {

    //Fill up the array by empty cells
    char arr[row][columns];
    char *ptr=&arr;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = '*';
        }
    }
    PrintTable(arr);//print empty gamefield

    //this loop is cycling the game before all fields don't filled up
    for (int i = 1; i < 9; i++) { //!start
        coutArr(arr);
    }

}


void gameLogic::coutArr(char arr[][columns]) {
    //block of local variables
    int rowIn, columnIn, checkIn;
    char in = ' ';// empty space for checking sequence

    cout << "Enter pozition(row /*space*/ column): ";
    cin >> rowIn >> columnIn;
    if (arr[rowIn][columnIn] == '*') { //make a cell constant
        cout << '\n' << "Now enter X or O(lowercase...I'll check!): ";
        cin >> in;
        //Check input values.
        checkIn = CheckXOFirst(in);
        switch (checkIn) {
            case 0: //compliance sequence
                system("cls");
                cout << in << " moved before,it's not your time!" << endl;
                this_thread::sleep_for(chrono::seconds(2));//w8 2 sec
                system("cls");
                break;
            case 1: // regular game time
                system("cls");
                cout << endl;
                arr[rowIn][columnIn] = in;
                PrintTable(arr);//print the game firld
                WinnerDetect(arr);// checking the win
                break;
            case 2: //Secret case...
                system("cls");
                cout << "\n \n \n \n \n I told you...";
                this_thread::sleep_for(chrono::seconds(2));//w8 2 sec
                GameOver();
                break;
            default: // Wrong input
                cout << endl;
                cout << endl;
                cout << "Wrong input.Try again.";
                this_thread::sleep_for(chrono::seconds(2));//w8 2 sec
                system("cls");
                break;
        }
    }
    else cout << "this cell already exist" << endl;

}

void gameLogic::WinnerDetect(char arr[][columns]) { //Detect the winner

    //check rows
    if (arr[2][2] != '*' && arr[1][1] != '*' && arr[3][3]) {
        if (arr[1][1] == arr[1][2] && arr[1][2] == arr[1][3]) {
            system("cls");
            cout << arr[1][1] << " is Winner!";
            exit(0);///drop the program
        }
        else if (arr[2][1] == arr[2][2] && arr[2][2] == arr[2][3]) {
            system("cls");
            cout << arr[2][1] << " is Winner!";
            exit(0);///drop the program
        }
        else if (arr[3][1] == arr[3][2] && arr[3][2] == arr[3][3]) {
            system("cls");
            cout << arr[3][1] << " is Winner!";
            exit(0);///drop the program
        }

            //check columns
        else if (arr[1][1] == arr[2][1] && arr[2][1] == arr[3][1]) {
            system("cls");
            cout << arr[1][1] << " is Winner!";
            exit(0);///drop the program
        }
        else if (arr[1][2] == arr[2][2] && arr[2][2] == arr[3][2]) {
            system("cls");
            cout << arr[2][2] << " is Winner!";
            exit(0);///drop the program
        }
        else if (arr[1][3] == arr[2][3] && arr[2][3] == arr[3][3]) {
            system("cls");
            cout << arr[2][3] << " is Winner!";
            exit(0);///drop the program
        }

            //check diagonal
        else if (arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3]) {
            system("cls");
            cout << arr[2][2] << " is Winner!";
            exit(0);///drop the program
        }
    }
}


//This function check input value
int gameLogic::CheckXOFirst(char a) {
    static char sequence = ' ';//store previous player
    cout << '_' << sequence << '_';
    if (a == 'x' || a == 'o') {
        //sequence check
        if (sequence == a) {  // if x,moving again gonna be error
            return 0;
        }
        else
            sequence = a;
        cout << '_' << sequence << '_';
        return 1;
    }
    else if (a == 'X' || a == 'O') {
        return 2;
    }
    else {
        return 3;
    }
}

void gameLogic::GameOver() {
    system("cls");
    cout << " .d8888b.                                  .d88888b.                         " << endl;
    cout << "d88P  Y88b                                d88P   Y88b                      " << endl;
    cout << "888    888                                888     888      " << endl;
    cout << "888        8888b. 88888b.d88b.  .d88b.    888     888888  888 .d88b. 888d888" << endl;
    cout << "888  88888    88b888   888  88bd8P  Y8b   888     888888  888d8P  Y8b888P\"" << endl;
    cout << "888    888.d888888888  888  88888888888   888     888Y88  88P88888888888 " << endl;
    cout << "Y88b  d88P888  888888  888  888Y8b.       Y88b. .d88P Y8bd8P Y8b.    888" << endl;
    cout << " Y8888P88  Y888888888  888  888  Y8888       Y88888P   Y88P   Y8888  888" << endl;

    exit(0);///drop the program
}

void gameLogic::PrintTable(char arr[][columns]) {
    cout << endl;
    cout << arr[1][1] << " | " << arr[1][2] << " | " << arr[1][3] << endl;
    cout << "- | - | -" << endl;
    cout << arr[2][1] << " | " << arr[2][2] << " | " << arr[2][3] << endl;
    cout << "- | - | -" << endl;
    cout << arr[3][1] << " | " << arr[3][2] << " | " << arr[3][3] << endl;
    cout << endl;
}

