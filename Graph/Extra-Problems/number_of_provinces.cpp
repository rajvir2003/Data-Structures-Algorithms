#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &visited, vector<int> adj[]){
    visited[node] = 1;

    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, visited, adj);
        }
    }
}

int numProvinces(int V, vector<int> adj[]){
    vector<int> visited(V, 0);
    int count = 0;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, visited, adj);
            count++;
        }
    }
    return count;
}

int main(){
    int V = 8; // number of nodes
    vector<int> adj[V];
    adj[0] = {1};
    adj[1] = {0,2};
    adj[2] = {1};
    adj[3] = {4};
    adj[4] = {3,5};
    adj[5] = {4};
    adj[6] = {7};
    adj[7] = {6};

    int ans = numProvinces(V, adj);
    cout << "Number of Provinces: " << ans << endl;

    return 0;
}