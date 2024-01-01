#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<int> &visited, vector<int> adj[], stack<int> &st){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it]){
            topoSort(it, visited, adj, st);
        }
    }
    st.push(node);
}

void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &v){
    visited[node] = 1;
    v.push_back(node);
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, visited, adj, v);
        }
    }
}

// this algorithm is used to find strongly connected components
int kosaraju(vector<int> adj[], int n, vector<vector<int>> &components){
    vector<int> visited(n,0);
    stack<int> st;
    // step1 : find topological ordering of nodes
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            topoSort(i, visited, adj, st);
        }
    }

    // step2 : reverse all edges of the graph
    vector<int> adj2[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0; // reset the visited vector, so that it can be used again while doing dfs
        for(auto it: adj[i]){
            adj2[it].push_back(i);
        }
    }

    // step3 : do dfs on topological ordering and find scc
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(visited[node] == 0){
            scc++;
            vector<int> v;
            dfs(node, visited, adj2, v);
            components.push_back(v);
        }
    }
    return scc;
}

int main(){
    int n = 5;
    vector<int> adj[n];
    adj[0] = {2,3};
    adj[1] = {0};
    adj[2] = {1};
    adj[3] = {4};
    adj[4] = {};

    vector<vector<int>> components;
    int scc = kosaraju(adj, n, components);
    cout << "Number of strongly connected components are: " << scc << endl;

    for(auto i: components){
        for(auto j : i){
            cout << j << " ";
        } cout << endl;
    }

    return 0;
}