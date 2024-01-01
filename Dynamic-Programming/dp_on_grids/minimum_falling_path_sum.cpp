#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j < 0 || j >= matrix.size()) return INT_MAX;
    if(i == 0) return matrix[0][j];

    if(dp[i][j] != -1) return dp[i][j];
    int up = f(i-1, j, matrix, dp);
    int ld = f(i-1, j-1, matrix, dp);
    int rd = f(i-1, j+1, matrix, dp);
    return dp[i][j] = matrix[i][j] + min(up, min(ld,rd));
}

int minFallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    // tabulation + space optimization
    vector<int> prev(n,0);
    for(int j = 0; j < n; j++){
        prev[j] = matrix[0][j];
    }

    vector<int> curr(n,0);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            int up, ld, rd;
            ld = rd = INT_MAX;
            up = prev[j];
            if(j > 0) ld = prev[j-1];
            if(j < n-1) rd = prev[j+1];
            curr[j] = matrix[i][j] + min(up, min(ld,rd));
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for(int j = 0; j < n; j++){
        ans = min(ans, prev[j]);
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };
    int ans = minFallingPathSum(matrix);
    cout << "Minimum falling path sum in the matrix: " << ans << endl;

    return 0;
}