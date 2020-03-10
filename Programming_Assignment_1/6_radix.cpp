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

// made a variation of counting sort to use in radixSort
// *** note that I simply based it off of my countingSort algorithm from this assignment
void countingSort(int arr[], int size, int divisor) {
    // temp will be used for swapping
    int temp[size], track[10];

    // initializing both arrays to 0 all throughout 
    for (int i = 0; i < size; i++)
        temp[i] = 0;
    for (int i = 0; i < 10; i++)
        track[i] = 0;

    // adding up instances of each digit
    for (int i = 0; i < size; i++)
        track[(arr[i]/divisor)%10]++;
    // let track[i] contain the number of elements less than or equal to i
    for (int i = 1; i < 10; i++)
        track[i] = track[i] + track[i-1];
    // build the array we will be using to swap with arr
    for (int i = size - 1; i > -1; i--) {
        temp[track[(arr[i]/divisor)%10] - 1] = arr[i];
        track[(arr[i]/divisor)%10]--;
    }
    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
}

void radixSort(int arr[], int size) {
    // asssuming we don't know that the largest possible number is 65535, we need to find the max number of digits
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    // finding the maximum numnber of digits
    int numDig = 0;
    while (max > 0) {
        numDig++;
        max /= 10;
    }
    
    int digPicker = 1;
    for (int i = 0; i < numDig; i++) {
        countingSort(arr, size, digPicker);
        digPicker *= 10;
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
    radixSort(arr, sizeof(arr)/sizeof(arr[0]));
    //printArr(arr, sizeof(arr)/sizeof(arr[0])); printf("\n");

    gettimeofday(&end, NULL);
    double time;
    time = (end.tv_sec - start.tv_sec) * 1e6;
    time = (time + (end.tv_usec - start.tv_usec)) * 1e-6;
    printf("%f\n", time);

    return 0;
}