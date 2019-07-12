//
// Created by dzirt on 7/6/2019.
//

#include "gameLogic.h"



void gameLogic::Start() {

    //Fill up the array by empty cells
    char arr[row][columns];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = '*';
        }
    }
    char (*arrPtr)[columns]=arr;//!!pointer to array!! after that all methods going to accept array trough pointer

    PrintTable(arrPtr);//print empty gamefield

    //this loop is cycling the game before all fields don't filled up
    for (int i = 1; i < 9; i++) { //!start
        coutArr(arrPtr);
    }

}


void gameLogic::coutArr(char (*arr)[columns]) {
    //block of local variables
    int rowIn, columnIn, checkIn;
    static char in = 'x';// char which gonna put into array
    static string player="Player X ";
    cout <<player<< "enter pozition(row /*space*/ column): ";
    cin >> rowIn >> columnIn;
    if (arr[rowIn][columnIn] == '*') { //make a cell constant
                system("cls");
                cout << endl;
                arr[rowIn][columnIn] = in;
                PrintTable(arr);//print the game field
                WinnerDetect(arr);// checking the win

    }
    else cout << "this cell already exist" << endl;

    //auto change
    if(in=='o'){
        in='x';
        player="Player X ";
    }else {
        in = 'o';
        player = "Player Y ";
    }
}


//int method below array values will be called by index,without pointers
void gameLogic::WinnerDetect(char (*arr)[columns]) { //Detect the winner

    //check rows
    if (arr[2][2] != '*' &&arr[3][3]  != '*' && arr[1][1] ) {
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


///method which working with pointers only!!!
void gameLogic::PrintTable(char (*arr)[columns]) {
    cout << endl;
    cout <<'\t'<< *(*(arr+1)+1) << " | " <<  *(*(arr+1)+2) << " | " << *(*(arr+1)+3)<< endl;   //the same sign like arr[row][column]
    cout << '\t'<<"- | - | -" << endl;
    cout <<'\t'<< *(*(arr+2)+1) << " | " <<  *(*(arr+2)+2) << " | " << *(*(arr+2)+3)<< endl;
    cout << '\t'<<"- | - | -" << endl;
    cout <<'\t'<< *(*(arr+3)+1) << " | " <<  *(*(arr+3)+2) << " | " << *(*(arr+3)+3)<< endl;
    cout << endl;
}

