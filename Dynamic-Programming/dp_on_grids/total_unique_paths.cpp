#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int up = f(i-1, j, dp);
    int left = f(i, j-1, dp);
    return dp[i][j] = up + left;
}

int uniquePaths(int n, int m){
    // vector<vector<int>> dp(n, vector<int>(m,-1));
    // return f(n-1, m-1, dp);

    // tabulation
    vector<int> prev(m,0);
    for(int i = 0; i < n; i++){
        vector<int> curr(m);
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) curr[j] = 1;
            else{
                int up = 0; int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j-1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[m-1]; 
}

int main(){
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    int count = uniquePaths(n,m);
    cout << "Total Unique Paths: " << count << endl;

    return 0;
}