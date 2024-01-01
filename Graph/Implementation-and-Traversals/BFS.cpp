#include<bits/stdc++.h>
using namespace std;

void bfs(int startNode, unordered_map<int,list<int>> adj){
    unordered_map<int,bool> visited;
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }
}

int main(){
    unordered_map<int,list<int>> adj; // adjacency list
    adj[0] = {1,4,2,3};
    adj[1] = {0,4,2};
    adj[2] = {1,0,4,3};
    adj[3] = {0,3,4};
    adj[4] = {0,2,3};

    int startNode = 0;
    map<int,bool> visited;
    bfs(startNode, adj);

    return 0;
}