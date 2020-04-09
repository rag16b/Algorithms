#include <iostream>
#include <stdio.h>

using namespace std;

long long findVal() {
    long long val = rand() % 2147483648;
    if (rand() % 2 == 0)
        val *= -1;
    return val;
}

int main() {

    

    return 0;
}