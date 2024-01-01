#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = INT_MAX;
    for(int k = i; k < j; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int n){
    // vector<vector<int>> dp(n, vector<int>(n,-1));
    // return f(1, n-1, arr, dp);

    // tabulation
    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int i = 1; i < n; i++) dp[i][i] = 0;

    for(int i = n-1; i >= 1; i--){
        for(int j = i+1; j < n; j++){
            int mini = INT_MAX;
            for(int k = i; k < j; k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}

int main(){
    vector<int> arr = {40,20,30,10,60,10,50};
    int n = arr.size();
    int minOP = matrixMultiplication(arr, n);
    cout << "Minimum operations: " << minOP << endl;

    return 0;
}