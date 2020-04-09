#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <fstream>

using namespace std;

long long findVal() {
    long long val = rand() % 2147483648;
    if (rand() % 2 == 0)
        val *= -1;
    return val;
}

int main() {

    srand (time(NULL));
    double loadFactor;
    int numVals;

    cout << "Please enter the load factor: ";
    cin >> loadFactor;
    numVals = loadFactor * 1000000;

    cout << loadFactor << " " << numVals << endl;

    ofstream file (to_string(numVals));
    if (file.is_open()) {
        file << numVals << endl;

        for (int i = 1; i < 100; i++) {
            file << findVal() << endl;
        }
    }

    return 0;
}