#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

void printArr(int arr[], int size) {
    printf("< ");
    int i = 0;
    for (i; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf(">");
}

void maxHeapify(int arr[], int size, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, size, largest);
    }
}

void buildMaxHeap(int arr[], int size) {
    for (int i = floor(size/2); i >= 0; i--)
        maxHeapify(arr, size, i);
}

void heapSort(int arr[], int size) {
    buildMaxHeap(arr, size);
    // from the top all the way down to the last element
    for (int i = size - 1; i >= 0; i--) {
        // exchange
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // reduce heap
        size--;
        // re-heapify
        maxHeapify(arr, size, 0);
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
    heapSort(arr, (sizeof(arr)/sizeof(arr[0])));
    //printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");

    return 0;
}