/* 
 * File:   main.h
 * Author: Jason Nawrocki
 *
 * Created on April 28, 2015, 8:15 PM
 */

#ifndef MAIN_H
#define	MAIN_H

GameBoard randomBoard();
void initTable(HashTable &table, int numBoards);
bool allDiff(GameBoard boards[4]);
void printData(int numBuckets, int numBoards, int numSearches);



#endif	/* MAIN_H */

