#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

long long findVal() {
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
    double loadFactor = 0.5;
    int numVals;
    long long key;
    long long funcH1;
    long long funcH;
    int numProbes = 0;
    int totalNumProbes = 0;
    double avgProbes;

    // table
    long long table[m];

    for (int i = 0; i < 5; i++) {

        numVals = loadFactor * m;

        // clearing the table
        for (int i = 0; i < m; i++)
            table[i] = 0;

        for (int i = 0; i < numVals; i++) {
            // reset num probes
            numProbes = 0;
            // generate random key in [-2^31, 2^31]
            key = findVal();

            // counter variable for our loop which resets right here
            int k = 0;
            do {
                // if the key is positive, hash normally; if it's negative, add table size back to value
                funcH1 = (key >= 0) ? key % m : key % m + m;
                // main function
                funcH = (funcH1 + k++) % m;

                // counting the number of probes
                numProbes++;

                // if we are stuck in a loop
                /*if (numProbes > m) {
                    cout << "Caught in an infinite loop" << endl;
                    break;
                }*/
            } while (table[funcH] != 0);

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