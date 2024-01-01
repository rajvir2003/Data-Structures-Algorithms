#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited){
    if((x >= 0 && x <= n-1) && (y >= 0 && y <= n-1) && m[x][y] == 1 && visited[x][y] == 0){
        return true;
    }
    else{
        return false;
    }
}
void solve(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited, string path, vector<string>& ans){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    
    // down
    if(isSafe(m, n, x+1, y, visited)){
        visited[x][y] = 1;
        path.push_back('D');
        solve(m, n, x+1, y, visited, path, ans);
        path.pop_back();
    }
    // left
    if(isSafe(m, n, x, y-1, visited)){
        visited[x][y] = 1;
        path.push_back('L');
        solve(m, n, x, y-1, visited, path, ans);
        path.pop_back();
    }
    // right
    if(isSafe(m, n, x, y+1, visited)){
        visited[x][y] = 1;
        path.push_back('R');
        solve(m, n, x, y+1, visited, path, ans);
        path.pop_back();
    }
    // up
    if(isSafe(m, n, x-1, y, visited)){
        visited[x][y] = 1;
        path.push_back('U');
        solve(m, n, x-1, y, visited, path, ans);
        path.pop_back();
    }
    
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    if(m[0][0] == 0){
        return ans;
    }
    string path = "";
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited = m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    visited[srcx][srcy] = 1;
    solve(m, n, srcx, srcy, visited, path, ans);
    return ans;
}

int main(){
    vector<vector<int>> m = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    int n = m.size();

    vector<string> result = findPath(m, n);
    for(auto i : result){
        cout << i << endl;
    }

    return 0;
}