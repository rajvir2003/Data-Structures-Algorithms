#include<bits/stdc++.h>
using namespace std;

/* Topological Sort -> Linear ordering of vertices such that if there is an edge 
                       between u and v, then u appears before v in that ordering.*/
/* Topological Sort is only valid in DAG (directed acyclic graph) */  
      
void dfs(int node, map<int,bool> &visited, map<int,list<int>> adj, stack<int> &st){
    visited[node] = true;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour, visited, adj, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, map<int, list<int>> adj){
    map<int, bool> visited;
    stack<int> st;
    // for disconnected components
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, visited, adj, st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    map<int, list<int>> adj;
    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0,1};
    adj[5] = {2,0};

    int V = adj.size();

    vector<int> v = topoSort(V, adj);
    for(auto i: v){
        cout << i << " ";
    } cout << endl;

    return 0;
}