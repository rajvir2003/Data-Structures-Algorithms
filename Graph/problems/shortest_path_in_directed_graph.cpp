#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &visited, map<int, list<pair<int,int>>> adj, stack<int> &s){
    visited[node] = 1;

    for(auto it: adj[node]){
        int v = it.first;
        if(!visited[v]){
            dfs(v, visited, adj, s);
        }
    }
    s.push(node);
}

vector<int> shortestDistance(int src, map<int, list<pair<int,int>>> adj, int N){
    // find topological sort
    vector<int> visited(N,0);
    stack<int> s;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            dfs(i, visited, adj, s);
        }
    }
    
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        
        for(auto it: adj[u]){
            int v = it.first;
            int wt = it.second;
            if(dist[u] != INT_MAX){
                dist[v] = min(dist[v], dist[u] + wt);
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(dist[i] == INT_MAX) dist[i] = -1;
    }
    return dist;
}

int main(){
    // directed weighted graph
    map<int, list<pair<int,int>> > adj;
    adj[0] = {{2,1}, {3,5}};
    adj[1] = {{0,2}};
    adj[2] = {{4,2}};
    adj[3] = {{5,4}};
    adj[4] = {{3,1}, {6,3}};
    adj[5] = {{6,1}};
    adj[6] = {{}};

    int N = adj.size();
    int src = 0;
    vector<int> dist = shortestDistance(src, adj, N);

    for(auto it: dist){
        cout << it << " ";
    } cout << endl;

    return 0;
}