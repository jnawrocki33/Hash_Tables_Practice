/* 
 * File:   main.cpp
 * Author: Jason Nawrocki
 *
 * Created on April 28, 2015, 8:10 PM
 */

/* 
 * File:   main.cpp
 * Author: smajerci
 *
 * Created on November 18, 2014, 7:22 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Entry.h"
#include "GameBoard.h"
#include "HashTable.h"
#include "main.h"

using namespace std;


int main(int argc, char** argv) {

    int numBoards = 10000;
    int numSearches = 2500000;
    cout << numBoards << " GameBoards inserted; "
            << numSearches << " searches" << endl << endl;

    
    // OUTPUT: PART 1
    // ------
    //
    // *** create required table of statistics with varying load factors
    int numBuckets;
    //print the data of all the following hash tables:
    numBuckets = 2000;
    printData(numBuckets, numBoards, numSearches);
    numBuckets = 2222;
    printData(numBuckets, numBoards, numSearches);
    numBuckets = 2500;
    printData(numBuckets, numBoards, numSearches);
    numBuckets = 2857;
    printData(numBuckets, numBoards, numSearches);
    numBuckets = 3333;
    printData(numBuckets, numBoards, numSearches);
    numBuckets = 4000;
    printData(numBuckets, numBoards, numSearches);
    numBuckets = 5000;
    printData(numBuckets, numBoards, numSearches);
    numBuckets = 6666;
    printData(numBuckets, numBoards, numSearches);
    numBuckets = 10000;
    printData(numBuckets, numBoards, numSearches);
    numBuckets = 20000;
    printData(numBuckets, numBoards, numSearches);
    
    
   
    // OUTPUT: PART 2
    // ------
    // NOTE: set DIMENSION in GameBoard.h to 4 for this section
    
    
    
    // *** make a hash table of size 100
    HashTable table = HashTable(100);
    // make an array of 4 GameBoards, all of which are different
    GameBoard boards[4];
    for (int i = 0; i < 4; ++i) {
        boards[i] = randomBoard();
    }
    while (allDiff(boards) == false) {
        for (int i = 0; i < 4; ++i) {
            boards[i] = randomBoard();
        }
    }
        
    // *** insert the first two boards into the hash table with arbitrary values
    table.insert(boards[0], 0);
    table.insert(boards[1], 1);   

    cout << "———————————————————------------------------————————" << endl << endl;
    cout << "ADDED BOARDS 1 AND 2 TO THE HASH TABLE" << endl << endl;
    cout << "———————————————————------------------------————————" << endl << endl;
    cout << "SEARCHES AFTER INSERTIONS BUT BEFORE REMOVALS" << endl << endl;
    cout << "———————————————————------------------------————————" << endl;


    cout << "Searching for Board 1 (which is in the hash table).  Board 1:" << endl << endl;
    boards[0].print();
    Entry e = table.find(boards[0]); // *** try to find boards[0] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Searching for Board 2 (which is in the hash table).  Board 2:" << endl << endl;
    boards[1].print();
    e = table.find(boards[1]);// *** try to find boards[1] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
    
        
    cout << "Searching for Board 3 (which is NOT in the hash table).  Board 3:" << endl << endl;
    boards[2].print();
    e = table.find(boards[2]);// *** try to find boards[2] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
    
        
    cout << "Searching for Board 4 (which is NOT in the hash table).  Board 4:" << endl << endl;
    boards[3].print();
    e = table.find(boards[3]);// *** try to find boards[3] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
    
    cout << "REMOVALS" << endl << endl;
    cout << "———————————————————------------------------————————" << endl;
    cout << "Removing Board 1 (which is in the hash table):" << endl << endl;
    boards[0].print();
    e = table.remove(boards[0]);   // *** remove boards[0]
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Removing Board 2 (which is in the hash table):" << endl << endl;
    boards[1].print();
    e = table.remove(boards[1]);  // *** remove boards[1]
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Removing Board 3 (which is NOT in the hash table):" << endl << endl;
    boards[2].print();
    e = table.remove(boards[2]); // *** remove boards[2]
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Removing Board 4 (which is NOT in the hash table):" << endl << endl;
    boards[3].print();
    e = table.remove(boards[3]); // *** remove boards[3]
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    
    cout << "SEARCHES AFTER REMOVALS" << endl << endl;
    cout << "———————————————————------------------------————————" << endl;
        
    cout << "Searching for Board 1 (no longer in the hash table).  Board 1:" << endl << endl;
    boards[0].print();
    e = table.find(boards[0]); // *** try to find boards[0] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Searching for Board 2 (no longer in the hash table).  Board 2:" << endl << endl;
    boards[1].print();
    e = table.find(boards[1]); // *** try to find boards[1] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Call to isEmpty function returns:  " << table.isEmpty() << endl << endl;
    
    cout << "———————————————————------------------------————————" << endl << endl;

    
    return EXIT_SUCCESS;

}



//
// Inputs: None.
//
// Output: A random gameboard.
//
// Creates and returns a GameBoard containing random
// integers
//

GameBoard randomBoard() {

    GameBoard board;
    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x < board.size(); x++) {
            double fval = rand() * 17;
            int value = (int) fval;
            board.setElementAt(x, y, value);
        }
    }
    return board;

}



//
// Inputs: A HashTable and an integer specifiying the
//         number of random Gameboards to be inserted
//         into the table.
//
// Output: None.
//
// The specified number of GameBoards is created and
// inserted into the HashTable. The value associated
// with each board is just the value of the for-loop
// control variable, since, for this lab, this value
// does not matter.
//

void initTable(HashTable &table, int numBoards) {
    for (int i = 0; i < numBoards; i++) {
        table.insert(randomBoard(), i);
    }
}


//
// Inputs: An array of 4 GameBoards.
//
// Output: A Boolean value:
//           - true if all 4 boards are different
//           - false, otherwise
//

bool allDiff(GameBoard boards[4]) {

    return
    !boards[0].equals(boards[1]) &&
            !boards[0].equals(boards[2]) &&
            !boards[0].equals(boards[3]) &&
            !boards[1].equals(boards[2]) &&
            !boards[1].equals(boards[3]) &&
            !boards[2].equals(boards[3]);


}

//This function prints the number of buckets, load factor, variance, and time
//taken to do 25000000 searches in a given hash table.
//The print is made with specific formatting 
void printData(int numBuckets, int numBoards, int numSearches) {
    double start, end, seconds;
    HashTable table2 = HashTable(numBuckets);
    initTable(table2, numBoards);
    start = clock();
    for (int i = 0; i < numSearches; ++i) {
        table2.find(randomBoard());
    }
    end = clock();
    seconds = (end - start) / CLOCKS_PER_SEC;
    //table1.printListSizes();
    cout << "number buckets: " << setw(5) << numBuckets << "     load factor: " 
            << setw(5) << setprecision(2) << setiosflags(ios::fixed) 
            << table2.getLoadFactor(numBoards) << "      variance: "
            << setw(5) << setprecision(3) << table2.calcVariance() << "     seconds: "
            << setw(10) << setprecision(8) << seconds << " seconds" << endl;
}




