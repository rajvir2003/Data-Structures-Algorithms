#include<bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &visited, vector<int> &mark, int tin[], int low[], vector<int> adj[]){
    visited[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;

    for(auto it: adj[node]){
        if(it == parent) continue;
        if(!visited[it]){
            dfs(it, node, visited, mark, tin, low, adj);
            low[node] = min(low[node], low[it]);
            // check articulation point
            if(low[it] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
    if(child > 1 && parent == -1){
        mark[node] = 1;
    }
}

vector<int> articulation_points(vector<int> adj[], int n){
    vector<int> visited(n,0);
    vector<int> mark(n,0);
    int tin[n];
    int low[n];
    dfs(0, -1, visited, mark, tin, low, adj);
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(mark[i] == 1) v.push_back(i);
    }
    return v;
}

int main(){
    int n = 7;
    vector<int> adj[n];
    adj[0] = {1,2,3};
    adj[1] = {0};
    adj[2] = {0,3,4,5};
    adj[3] = {2,0};
    adj[4] = {2,6};
    adj[5] = {6,2};
    adj[6] = {4,5};

    // articulation points -> nodes on whose removal the graph breaks down into multiple components.
    vector<int> AP = articulation_points(adj, n);
    cout << "Articulation points in the graph are: ";
    for(auto i: AP){
        cout << i << " ";
    } cout << endl;

    return 0;
}