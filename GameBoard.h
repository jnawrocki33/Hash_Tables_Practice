/* 
 * File:   GameBoard.h
 * Author: Jason Nawrocki
 *
 * The GameBoard class has a 2x2 array which is the board
 * It has functionality to alter the gameboard items, test if two boards are
 * identical, and also it has a hash function which gives a hash code of a 
 * given board
 * 
 * Created on April 28, 2015, 8:12 PM
 */

/* 
 * File:   GameBoard.h
 * Author: smajerci
 *
 * Created on November 18, 2014, 7:24 PM
 */

#ifndef GAMEBOARD_H
#define	GAMEBOARD_H
#define LARGE_PRIME 16908799

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class GameBoard {
    
public:
    GameBoard();
    GameBoard(int setValue);

    void setElementAt(int x, int y, int value);
    int size() { return DIMENSION; }
    int elementAt(int x, int y) {return board[x][y]; }
    bool equals(GameBoard board);
    int hashCode();
    void print();


private:
    static const int DIMENSION = 4;
    int board[DIMENSION][DIMENSION];

};

#endif	/* GAMEBOARD_H */

