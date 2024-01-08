#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1,-1,0,+1,+1,+1,0,-1};
int dy[8] = {0,+1,+1,+1,0,-1,-1,-1};

int dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid){
    visited[row][col] = 1;
    
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < 8; i++){
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0
        && visited[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
            dfs(nrow, ncol, visited, grid);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m,0));
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                dfs(i, j, visited, grid);
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<char>> grid = {
        {'0','1','1','1','0','0','0'}, 
        {'0','0','1','1','0','1','0'}
    };
    int ans = numIslands(grid);
    cout << "Number of islands: " << ans << endl;
    
    return 0;
}