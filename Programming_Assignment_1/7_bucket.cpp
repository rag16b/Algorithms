#include <iostream>
#include <stdio.h>
using namespace std;

void bucketSort(int arr[], int n) {

    // will likely have to do this in c++ if I have to use vectors
    // check to make sure that the input will be U[0,1) real numbers (if it is, then a bucket of size 10 makes sense)
    vector<float> bucket[10];
}

void printArr(int arr[], int size) {
    printf("< ");
    int i = 0;
    for (i; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf(">\n");
}

int main() {
    int temp[] = {10, 11, 9, 0, 5, 8, 13};

    printArr(temp, sizeof(temp)/sizeof(temp[0]));
    bucketSort(temp, sizeof(temp)/sizeof(temp[0]));
    printArr(temp, sizeof(temp)/sizeof(temp[0]));

    return 0;
}