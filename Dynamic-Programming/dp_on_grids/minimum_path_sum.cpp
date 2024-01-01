#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];
    int up = f(i-1, j, grid, dp);
    int left = f(i, j-1, grid, dp);
    return dp[i][j] = grid[i][j] + min(up, left);
}

int minPathSum(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    // vector<vector<int>> dp(n, vector<int>(m,-1));
    // return f(n-1, m-1, grid, dp);

    // tabulation + space optimization
    vector<int> prev(m,0);
    for(int i = 0; i < n; i++){
        vector<int> curr(m,0);
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) curr[j] = grid[0][0];
            else{
                int up = INT_MAX;
                int left = INT_MAX;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j-1];
                curr[j] = grid[i][j] + min(up,left);
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

int main(){
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    
    int ans = minPathSum(grid);
    cout << "Minimum Path Sum: " << ans << endl;

    return 0;
}