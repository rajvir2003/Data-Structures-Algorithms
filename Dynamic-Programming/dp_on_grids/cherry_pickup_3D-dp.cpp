#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size()) return -1e8;
    if(i == grid.size()-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    // try all possible ways
    int maxi = INT_MIN;
    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += f(i+1, j1+dj1, j2+dj2, grid, dp);
            maxi = max(maxi,value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> front(m, vector<int>(m,0));
    // tabulation + space optimization
    for(int j1 = 0; j1 < m; j1++){
        for(int j2 = 0; j2 < m; j2++){
            if(j1 == j2) front[j1][j2] = grid[n-1][j1];
            else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }
    vector<vector<int>> curr(m, vector<int>(m,0));
    for(int i = n-2; i >= 0; i--){
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                int maxi = INT_MIN;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];
                        if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m) {
                            value += front[j1+dj1][j2+dj2];
                        }
                        else value = -1e8;
                        maxi = max(maxi,value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][m-1];
}

int main(){
    vector<vector<int>> grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };

    int ans = cherryPickup(grid);
    cout << "Maximum cherries taken by robot1 & robot2: " << ans << endl;
    
    return 0;
}