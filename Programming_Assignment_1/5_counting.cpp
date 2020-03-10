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

    struct timeval start, end;
    gettimeofday(&start, NULL);
    ios_base::sync_with_stdio(false);

    // this array will hold the output of counting sort
    int arrOut[size];
    //printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");
    countingSort(arr, arrOut, sizeof(arr)/sizeof(arr[0]), 65535);
    //printArr(arrOut, sizeof(arrOut)/sizeof(arrOut[0])); printf("\n");

    gettimeofday(&end, NULL);
    double time;
    time = (end.tv_sec - start.tv_sec) * 1e6;
    time = (time + (end.tv_usec - start.tv_usec)) * 1e-6;
    printf("%f\n", time);

    return 0;
}