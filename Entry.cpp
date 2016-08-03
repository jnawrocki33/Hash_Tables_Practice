/* 
 * File:   Entry.cpp
 * Author: Jason Nawrocki
 * 
 * Created on April 28, 2015, 8:11 PM
 */

/* 
 * File:   Entry.cpp
 * Author: smajerci
 * 
 * Created on November 18, 2014, 7:38 PM
 */

#include "Entry.h"


Entry::Entry() {
}


//constructor sets the board and integer value in the entry
Entry::Entry(GameBoard board, int value) { 
    this->board = board; 
    this->value = value; 
}




