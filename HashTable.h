/* 
 * File:   HashTable.h
 * Author: Jason Nawrocki
 *
 * This is the HashTable class.
 * It uses open hashing with vectors to handle collisions.
 * It has many functionalities, which include getting statistics about the
 * hash table such as load factor and variance of list sizes.
 * It also includes a compression function.
 * 
 * Created on April 28, 2015, 8:14 PM
 */


#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Entry.h"
#include "GameBoard.h"

using namespace std;

class HashTable {
public:
    HashTable(int n);
    HashTable(const HashTable& orig);
    virtual ~HashTable() {delete[] table;}   //destructor frees the memory
    
    int compress(int hashVal);
    Entry insert(GameBoard board, int i);
    Entry find(GameBoard board);
    Entry remove(GameBoard board);
    
    bool isEmpty();
    double getLoadFactor(int numBoards) {return double(numBoards) / getNumBuckets();}
    int getNumBuckets() {return size;}
    int getNumItems();
    void printListSizes();
    void makeEmpty();
    
    double calcVariance();
    
     
private:
    vector <Entry>* table;
    int size;

};

#endif	/* HASHTABLE_H */



