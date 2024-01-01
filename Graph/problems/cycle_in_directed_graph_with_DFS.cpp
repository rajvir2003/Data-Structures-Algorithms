#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node, map<int,bool> &visited, map<int,bool> &dfsVisited, map<int, list<int>> adj){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it]){
            if(detectCycle(it, visited, dfsVisited, adj)) return true;
        }
        else if(dfsVisited[it]) return true;
    }
    dfsVisited[node] = false;
    return false;
}

int main(){
    map<int, list<int>> adj;
    adj[1] = {2};
    adj[2] = {6,3};
    adj[3] = {4};
    adj[4] = {5};
    adj[5] = {3};
    adj[6] = {7,8};
    adj[7] = {};
    adj[8] = {7};

    map<int, bool> visited;
    map<int, bool> dfsVisited; // keep track of nodes present in the path
    if(detectCycle(1, visited, dfsVisited, adj)){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle Detected" << endl;
    }

    return 0;
}