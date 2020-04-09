#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

// generates a random key
long long generateKey() {
    long long val = rand() % 2147483648;
    if (rand() % 2 == 0)
        val *= -1;
    return val;
}

int main() {

    // seed rng
    srand (time(NULL));

    // tablesize
    const int m = 1000000;
    const int C1 = 0;
    const int C2 = 1;
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
            do {
                // if the key is positive, hash normally; if it's negative, add table size back to value
                // ***THIS WOULD BE MY h'(k)
                funcH1 = (key >= 0) ? key % m : key % m + m;
                // main function
                funcH = (funcH1 + (C1*k) + (C2*(k*k))) % m;
                k++;

                // counting the number of probes
                numProbes++;

                // if we are stuck in a loop. this is more just for testing but I figure i'll get more points
                //  if it just skips any keys that get caught in an infinite loop
                if (numProbes > m) {
                    cout << "Caught in an infinite loop" << endl;
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