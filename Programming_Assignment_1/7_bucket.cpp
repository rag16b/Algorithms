#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <sys/time.h>
using namespace std;

void printArr(float arr[], int size) {
    printf("< ");
    int i = 0;
    for (i; i < size; i++) {
        printf("%.*f ", 2, arr[i]);
    }
    printf(">\n");
}

void bucketSort(float arr[], int size) {
    vector<float> bucket[size];

    // placing elements in their repective buckets
    for (int i = 0; i < size; i++) {
        int index = arr[i]*size;
        bucket[index].push_back(arr[i]);
    }

    // sorting each bucket
    for (int i = 0; i < size; i++) {
        int pos;
        for (int j = 0; j < bucket[i].size(); j++) {
            pos = j;
            for (int k = j + 1; k < bucket[i].size(); k++) {
                if (bucket[i][k] < bucket[i][pos])
                    pos = k;
            }
    
            // swap
            float temp = bucket[i][pos];
            bucket[i][pos] = bucket[i][j];
            bucket[i][j] = temp;
        }
    }

    // concatenating the lists together
    int currentIndex = 0;
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < bucket[i].size(); k++)
            arr[currentIndex++] = bucket[i][k];
    }
}

int main() {
    int size;
    float num;
    cin >> size;
    float arr[size];
    for (int i = 0; i < size; i++) {
        cin >> num;
        arr[i] = num;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);
    ios_base::sync_with_stdio(false);

    //printArr(arr, sizeof(arr)/sizeof(arr[0]));
    bucketSort(arr, sizeof(arr)/sizeof(arr[0]));
    //printArr(arr, sizeof(arr)/sizeof(arr[0]));

    gettimeofday(&end, NULL);
    double time;
    time = (end.tv_sec - start.tv_sec) * 1e6;
    time = (time + (end.tv_usec - start.tv_usec)) * 1e-6;
    printf("%f\n", time);

    return 0;
}