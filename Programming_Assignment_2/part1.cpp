#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

// generates a random key
long long generateKey() {
    long long val = rand() % 2147483648;
    if (rand() % 2 == 0)
        val *= -1;
    return val;
}

int chooseRand(int key, int pos, int bucketsLeft) {

    static unsigned int seed = key;
 
    // Create a large number so that it can get overflowed
    int rand = 8462154 * seed + 2498762;
    return rand % bucketsLeft;
}

int main() {

    // seed rng
    srand (time(NULL));

    // tablesize
    const int m = 1000000;
    double loadFactor = 0.5;
    int numVals;
    long long key;
    long long funcH1;
    long long funcH;
    int numProbes = 0;
    int totalNumProbes = 0;
    double avgProbes;
    const int emptyVal = 2147483649;

    // table
    long long table[m];
    // this array will be used to randomly select elements for the hash function
    // (doesn't need to be long long but i did it just in case)
    static long long posPicker[m];
    for (int i = 0; i < m; i++)
        posPicker[i] = i;

    for (int j = 0; j < 5; j++) {

        numVals = loadFactor * m;

        // clearing the table
        for (int i = 0; i < m; i++)
            table[i] = emptyVal;

        for (int i = 0; i < numVals; i++) {
            // reset num probes
            numProbes = 0;
            // generate random key in [-2^31, 2^31]
            key = generateKey();

            // counter variable for our loop which resets right here
            int k = 0;
            int sizeOfPosPicker = m;
            do {
                if (sizeOfPosPicker != 0) {
                    int pRand = chooseRand(key, k, sizeOfPosPicker);
                    // Let the element we just grabbed be replaced by the last element since we no longer need it
                    // Decrement the array size to act as though we removed the last element to make sure we are choosing 
                    //  from a smaller set of original positions
                    int temp = posPicker[pRand];
                    posPicker[pRand] = posPicker[sizeOfPosPicker];
                    posPicker[sizeOfPosPicker--] = temp;
                
                   // if the key is positive, hash normally; if it's negative, add table size back to value
                    // ***THIS WOULD BE MY h'(k)
                    funcH1 = (key >= 0) ? key % m : key % m + m;
                    // main function
                    funcH = (funcH1 + pRand) % m;
                    k++;
                }

                // counting the number of probes
                numProbes++;

                // if we are stuck in a loop. this is more just for testing but I figure i'll get more points
                //  if it just skips any keys that get caught in an infinite loop
                if (numProbes > m) {
                    //cout << "Caught in an infinite loop" << endl;
                    break;
                }
            } while (table[funcH] != emptyVal);

            table[funcH] = key;
            totalNumProbes += numProbes;
        }

        avgProbes = (totalNumProbes * 1.0)/numVals;
        cout << avgProbes << endl;

        // resetting totalNumProbes and incrementing loadFactor
        totalNumProbes = 0;
        loadFactor += 0.1;
    }

    return 0;
}