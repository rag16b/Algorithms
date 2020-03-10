#include <iostream>
#include <stdio.h>
#include <math.h>
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

void merge(int arr[], int p, int q, int r) {
    
    int n1 = q - p + 1;
    int n2 = r - q;
    // temporary arrays
    int L[n1], R[n2];

    // copying the data into the arrays
    int i, j;
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    /*
    printArr(L, sizeof(L)/sizeof(L[0]));
    printf(" ");
    printArr(R, sizeof(R)/sizeof(R[0]));
    printf("\n");
    */

    // merging the temporary arrays
    i = 0;
    j = 0;
    int k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }

    // copying possible left overs from L[]
    while (i < n1)
        arr[k++] = L[i++];
    // copying possible left overs from R[]
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        // needed to do r-p in case of overflow
        int q = floor((p+(r-p)/2));
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
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
    mergeSort(arr, 0, (sizeof(arr)/sizeof(arr[0]) - 1));
    //printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");

    gettimeofday(&end, NULL);
    double time;
    time = (end.tv_sec - start.tv_sec) * 1e6;
    time = (time + (end.tv_usec - start.tv_usec)) * 1e-6;
    printf("%f\n", time);

    return 0;
}