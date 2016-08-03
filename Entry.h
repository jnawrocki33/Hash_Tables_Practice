/* 
 * File:   Entry.h
 * Author: Jason Nawrocki
 *
 * Created on April 28, 2015, 8:11 PM
 */

/* 
 * File:   Entry.h
 * Author: smajerci
 *
 * Entry class packages a gameBoard with an associated (in this case arbitrary)
 * integer value
 * Created on November 18, 2014, 7:38 PM
 */

#ifndef ENTRY_H
#define	ENTRY_H

#include "GameBoard.h"
#include "Entry.h"

class Entry {
    
public:
    Entry();
    Entry(GameBoard board, int value);
    GameBoard getBoard() { return board; }
    int getValue() { return value; } 
    
private:
    GameBoard board;
    int value;
    
};

#endif	/* ENTRY_H */



