/* 
 * File:   GameBoard.cpp
 * Author: Jason Nawrocki
 * 
 * Created on April 28, 2015, 8:12 PM
 */


/* 
 * File:   GameBoard.cpp
 * Author: smajerci
 * 
 * Created on November 18, 2014, 7:24 PM
 */

#include "GameBoard.h"


//basic constructor
GameBoard::GameBoard() {
}

//this constructor makes a board where every value is the same, equal to
//an input. It is used to create the fail board with -1's
GameBoard::GameBoard(int setValue) {
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            board[r][c] = setValue;
        }
    }
}

//this function sets the value of the board at a specific position to a value
void GameBoard::setElementAt(int x, int y, int value) {
    board[x][y] = value % 3;
    if (board[x][y] < 0) {
        board[x][y] = board[x][y] + 3;
    }
}


//this function tests if two boards are equal, and returns true if they are
bool GameBoard::equals(GameBoard board) {

    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            if (this->board[r][c] != board.elementAt(r, c))
                return false;
        }
    }

    return true;
}


//this function creates a hash value for a specific gameboard
//it returns the integer hash value
int GameBoard::hashCode() {

    int hashVal = 0;

    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            //at each element, increase the hash value by a power of 127. 
            //then add the element value to the hash value.
            //then mod by a large prime
            hashVal = ((127 * hashVal) + board[r][c]) % LARGE_PRIME;
        }
    }
    
    return hashVal;
}

//this function prints a gameboard
void GameBoard::print() {
    for (int r = 0; r < DIMENSION; r++)  {
        for (int c = 0; c < DIMENSION; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}
