#include <iostream>
#include <stdio.h>
using namespace std;

void printArr(int arr[], int size) {
    printf("< ");
    int i = 0;
    for (i; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf(">");
}

void countingSort(int arrA[], int arrB[], int size, int k) {
    int temp[k];
    // initialize the temporary array
    for (int i = 0; i < k; i++)
        temp[i] = 0;
    // for all j, assuming a limit of "size", increment so that temp[i] contains the number of elements equal to i
    for (int j = 0; j < size; j++)
        temp[arrA[j] + 1]++;
    // then let temp[i] contain the number of elements less than or equal to i
    for (int i = 0; i < k; i++)
        temp[i] = temp[i] + temp[i-1];

    // for testing
    /*for (int i = 0; i < size; i++)
        arrB[i] = 0;*/
    
    for (int j = size - 1; j > -1; j--) {
        arrB[temp[arrA[j]]] = arrA[j];
        temp[arrA[j]]--;

        // for testing
        /*printArr(arrB, size);
        printf("\n");*/
    }
}

int main() {
    int size, num;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> num;
        arr[i] = num;
    }

    // this array will hold the output of counting sort
    int arrOut[size];
    printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");
    countingSort(arr, arrOut, sizeof(arr)/sizeof(arr[0]), 65535);
    printArr(arrOut, sizeof(arrOut)/sizeof(arrOut[0])); printf("\n");

    return 0;
}