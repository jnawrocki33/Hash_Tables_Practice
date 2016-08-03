/* 
 * File:   HashTable.cpp
 * Author: Jason Nawrocki
 * 
 * Created on April 28, 2015, 8:14 PM
 */
/* 
 * File:   HashTable.cpp
 * Author: Jason
 * 
 * Created on April 27, 2015, 9:33 PM
 */

#include "HashTable.h"

//The constructor for the hash table takes parameter n, which is the size
//It also dynamically allocated memory for the hash table.
HashTable::HashTable(int n) {
    vector <Entry>* arr;
    arr = new vector <Entry> [n];
    table = new vector <Entry> [n];
    size = n;
}

HashTable::HashTable(const HashTable& orig) {
}

//This is the function which inserts a GameBoard into the hash table
//It packages the board and a value, both parameters, into an entry
//Then calculates the index by hashing and compressing the board
//It returns the entry that was inserted
Entry HashTable::insert(GameBoard board, int i) {
    
    Entry entry = Entry(board, i);
    int hashVal = board.hashCode();
    int index = compress(hashVal);
    table[index].push_back(entry);
    return entry;
}

//This function searches the hash table for a specific game board
//It also returns the entry that if found, or a fail entry if the board
//wasn't in the table
Entry HashTable::find(GameBoard board) {

    //get the index where the board would be located
    int hashVal = board.hashCode();
    int index = compress(hashVal);
    vector <Entry> vect = table[index];
    //check all the items in the vector at that index
    for (int i = 0; i < vect.size(); ++i) {
        if (board.equals(vect.at(i).getBoard()) == true) {
            //cout << "found" << endl;
            return vect.at(i);
        }
    }
    
    //Otherwise, failure
    GameBoard failBoard = GameBoard(-1);
    Entry failEntry = Entry(failBoard, -99);
    return failEntry;
}

//This function searches the hash table for a game board, and removes it if
//found. it also returns the board if found, or a fail-board if not.
Entry HashTable::remove(GameBoard board) {
    //same as find function
    int hashVal = board.hashCode();
    int index = compress(hashVal);
    vector <Entry>::iterator it = table[index].begin();
    for (int i = 0; i < table[index].size(); ++i) {
        //if found, delete it
        if (board.equals(table[index].at(i).getBoard()) == true) {
            Entry deleteEntry = table[index].at(i);
            table[index].erase(it);
            return deleteEntry;
        }
        ++it;
    }
    
    //Otherwise, failure
    GameBoard failBoard = GameBoard(-1);
    Entry failEntry = Entry(failBoard, -99);
    return failEntry;
}

//compression function. given a hash value, it compresses it to a valid index
//using mod size
int HashTable::compress(int hashVal) {
    return (((2 * hashVal) + 7) % LARGE_PRIME) % size; 
}

//this function checks if each vector in the hash table is empty
bool HashTable::isEmpty() {
    for (int i = 0; i < size; ++i) {
        if (table[i].size() != 0) {
            return false;
        }
    }
    return true;
}

//this function gets the number of items in the hash table by checking the 
//size of each vector
int HashTable::getNumItems() {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        count += table[i].size();
    }
    return count;
}

//this function prints the size of each vector in the hash table
void HashTable::printListSizes() {
    for (int i = 0; i < size; ++i) {
        cout << table[i].size() << endl;
    }
}

//this function empties each vector in the hash table
void HashTable::makeEmpty() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < table[i].size(); ++j){
            table[i].pop_back();
        }
    }
}

//this function calculates the variance of the list sizes in the hash table
double HashTable::calcVariance() {
    //calculate the mean
    double mean;
    double count = 0;
    for (int i = 0; i < size; ++i) {
        count = count + table[i].size();
    }
    mean = count/size;
    double var;
    double countDiff = 0;
    //using the mean, calculate the variance
    for (int i = 0; i < size; ++i) {
        countDiff = countDiff + (table[i].size() - mean) * (table[i].size() - mean);
    }
    var = (1.0 / size) * countDiff;
    return var;
}

