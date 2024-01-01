#include<bits/stdc++.h>
using namespace std;

void dfs(int node, map<int, list<int>> adj, unordered_map<int, bool> &visited){
    cout << node << " ";
    visited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, adj, visited);
        }
    }
}

int main(){
    map<int, list<int>> adj;
    adj[0] = {1,2,3};
    adj[1] = {0,2};
    adj[2] = {1,0,3,4};
    adj[3] = {0,2,4};
    adj[4] = {3,2,5,6};
    adj[5] = {4};
    adj[6] = {4};

    unordered_map<int, bool> visited;
    int startNode = 3;
    dfs(startNode, adj, visited);

    return 0;
}