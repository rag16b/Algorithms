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

void radixSort() {
    
}

int main() {
    int size, num;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> num;
        arr[i] = num;
    }

    printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");
    radixSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");

    return 0;
}