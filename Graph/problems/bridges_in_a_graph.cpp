#include<bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &visited, int tin[], int low[], vector<int> adj[], vector<pair<int,int>> &bridges){
    visited[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for(auto it: adj[node]){
        if(it == parent) continue;
        if(!visited[it]){
            dfs(it, node, visited, tin, low, adj, bridges);
            low[node] = min(low[node], low[it]);
            // check for bridge
            if(low[it] > tin[node]){
                bridges.push_back({node,it});
            } 
        }
        else{
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<pair<int,int>> find_Bridges(vector<int> adj[], int n){
    vector<int> visited(n,0);
    int tin[n];
    int low[n];
    vector<pair<int,int>> bridges;
    dfs(1, -1, visited, tin, low, adj, bridges);
    return bridges;
}

int main(){
    int n = 13;
    vector<int> adj[n];
    adj[1] = {2,4};             
    adj[2] = {1,3};             
    adj[3] = {2,4};             
    adj[4] = {1,5,3};
    adj[5] = {4,6};
    adj[6] = {5,7,9};
    adj[7] = {6,8};
    adj[8] = {7,9,10};
    adj[9] = {8,6};
    adj[10] = {8,11,12};
    adj[11] = {10,12};
    adj[12] = {11,10};

    vector<pair<int,int>> bridges = find_Bridges(adj, n);
    for(auto it: bridges){
        cout << "[" << it.first << "," << it.second << "]" << endl;
    }

    return 0;
}