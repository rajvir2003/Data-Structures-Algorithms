#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> m, vector<vector<int>> visited, int n){
    if((x < n && x >= 0) && (y < n && y >= 0) && m[x][y] == 1 && visited[x][y] == 0){
        return true;
    }
    return false;
}
    
void solve(int x, int y, vector<vector<int>> m, vector<vector<int>> visited, int n, string path, vector<string> &output){
    if(x == n-1 && y == n-1){
        output.push_back(path);
        return;
    }
    
    // down
    if(isSafe(x+1,y,m,visited,n)){
        visited[x][y] = 1;
        path.push_back('D');
        solve(x+1,y,m,visited,n,path,output);
        path.pop_back();
    }
    // left
    if(isSafe(x,y-1,m,visited,n)){
        visited[x][y] = 1;
        path.push_back('L');
        solve(x,y-1,m,visited,n,path,output);
        path.pop_back();
    }
    // right
    if(isSafe(x,y+1,m,visited,n)){
        visited[x][y] = 1; 
        path.push_back('R');
        solve(x,y+1,m,visited,n,path,output);
        path.pop_back();
    }
    // up
    if(isSafe(x-1,y,m,visited,n)){
        visited[x][y] = 1;
        path.push_back('U');
        solve(x-1,y,m,visited,n,path,output);
        path.pop_back();
    }
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    string path = "";
    vector<string> output;
    if(m[0][0] == 0){
        return output;
    }
    vector<vector<int>> visited = m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        } 
    }

    int posX = 0;
    int posY = 0;
    solve(posX, posY, m, visited, n, path, output);
    return output;
}

int main(){
    vector<vector<int>> m = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    int n = m.size();

    vector<string> ans = findPath(m, n);
    for(auto i : ans){
        cout << i << endl;
    }

    return 0;
}