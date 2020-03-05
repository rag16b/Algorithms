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
        printArr(arr, size);
        printf("\n");
    }
}

int main() {
    int temp[] = {10, 11, 9, 0, 5, 8, 13};

    printArr(temp, sizeof(temp)/sizeof(temp[0]));
    printf("\n");
    insertionSort(temp, sizeof(temp)/sizeof(temp[0]));

    return 0;
}