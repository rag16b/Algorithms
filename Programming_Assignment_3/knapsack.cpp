#include <iostream>
#include <cmath>

using namespace std;

// the variables mean (n: the number of items in the knapsack, W: the capacity or maximum possible weight of the knapsack,
//                     w[]: the array containing the weight for each item i, v[]: the array containing the value for each item i)
int knapsack(int n, int W, int w[], int v[]) {

    // initializing K
    int **K;
    K = new int * [n+1];
    for (int i = 0; i < n+1; i++)
        K[i] = new int[W+1];

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < W+1; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (w[i-1] <= j)
                K[i][j] = ((v[i-1] + K[i-1][j-w[i-1]]) > K[i-1][j]) ? (v[i-1] + K[i-1][j-w[i-1]]) : K[i-1][j];
            else
                K[i][j] = K[i-1][j];
        }
    }

    // Getting the items included in the knapsack ------------------
    // ***THIS IS NOT PART OF THE ALGORITHM BUT I INCLUDED IT IN THE
    //    FUNCTION BECAUSE I NEED THE TABLE 'K' TO FIGURE THIS OUT
    cout << "List of items in the knapsack (value, weight): ";
    int i = n;
    int j = W;
    int totalWeight = 0;
    while (i > 0 && j > 0) {
        if (K[i][j] == K[i-1][j]) {     // item is NOT in knapsack
            i--;
        }
        else {      // item is in knapsack
            j = j - w[i];
            i--;
            cout << "(" << v[i] << ", " << w[i] << ") ";
            totalWeight += w[i];
        }
    }
    cout << endl;
    //cout << "Weight of all items: " << totalWeight << endl;
    // -------------------------------------------------------------
    
    return K[n][W];
}

int main () {

    int n = 100;
    int W = 335732;
    int w[n], v[n];

    for (int i = 0; i < n; i++) {
        w[i] = round(1000*sqrt(i+1));
        v[i] = 1;
    }

    int result = knapsack(n, W, w, v);
    cout << "Value of the optimal knapsack: " << result << endl;

    return 0;
}