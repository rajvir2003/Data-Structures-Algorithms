#include<bits/stdc++.h>
using namespace std;

/* This problem is based on multi-source bfs */

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,pair<int,int>>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({0,{i,j}});
                grid[i][j] = 2;
            }
        }
    }

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int maxi = 0;
    while(!q.empty()){
        int time = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        maxi = max(maxi, time);

        for(int i = 0; i < 4; i++){
            int nRow = r + dx[i];
            int nCol = c + dy[i];
            if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0 && grid[nRow][nCol] == 1){
                q.push({time+1,{nRow,nCol}});
                grid[nRow][nCol] = 2;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1) return -1;
        }
    }
    return maxi;
}

int main(){
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int ans = orangesRotting(grid);
    cout << "Total time to rotten all oranges: " << ans << endl;

    return 0;
}