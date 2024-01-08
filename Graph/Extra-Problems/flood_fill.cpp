#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size(); int m = image[0].size();
    queue<pair<int,int>> q;
    q.push({sr,sc});
    int oldColor = image[sr][sc];
    image[sr][sc] = color;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nRow = r + dx[i];
            int nCol = c + dy[i];
            if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0 
            && image[nRow][nCol] == oldColor && image[nRow][nCol] != color){
                image[nRow][nCol] = color;
                q.push({nRow, nCol});
            }
        }
    }
    return image;
}

int main(){
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    vector<vector<int>> newImage = floodFill(image,1,1,2);
    for(auto i: newImage){
        for(auto j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    return 0;
}