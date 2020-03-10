#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <sys/time.h>
using namespace std;

void printArr(int arr[], int size) {
    printf("< ");
    int i = 0;
    for (i; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf(">");
}

int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int k = p; k < r; k++) {
        if (arr[k] <= x) {
            i++;
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
    int temp2 = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp2;
    return i + 1;
}

void quickSort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
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

    struct timeval start, end;
    gettimeofday(&start, NULL);
    ios_base::sync_with_stdio(false);

    //printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");
    quickSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    //printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");

    gettimeofday(&end, NULL);
    double time;
    time = (end.tv_sec - start.tv_sec) * 1e6;
    time = (time + (end.tv_usec - start.tv_usec)) * 1e-6;
    printf("%f\n", time);

    return 0;
}