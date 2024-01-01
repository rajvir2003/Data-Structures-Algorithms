#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    // n = no. of nodes
    // m = no. of edges
    cin >> n >> m;

    vector<vector<int>> matrix(n+1, vector<int>(n+1,0));
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    for(auto i: matrix){
        for(auto j: i){
            cout << j << " ";
        } cout << endl;
    }

    return 0;
}