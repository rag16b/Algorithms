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

void insertionSort(int arr[], int size) {
    int i, j = 1, key;
    for (j; j < size; j++) {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
        //printArr(arr, size);
        //printf("\n");
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

    //printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");
    insertionSort(arr, sizeof(arr)/sizeof(arr[0]));
    //printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");

    return 0;
}