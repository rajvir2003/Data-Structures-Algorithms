#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int node, int parent, map<int, bool> &visited, map<int, list<int>> &adj){
    visited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it]){
            if(detectCycle(it, node, visited, adj)){
                return true;
            }
        }
        else if(it != parent){
            return true;
        }
    }
    return false;
}

int main(){
    map<int, list<int>> adj;
    adj[1] = {2,3};
    adj[2] = {1,4};
    adj[3] = {5,9,1};
    adj[4] = {2,6};
    adj[5] = {3,8};
    adj[6] = {4,7};
    adj[7] = {6,8};
    adj[8] = {7,5};
    adj[9] = {3};

    int startNode = 1;
    map<int, bool> visited;

    if(detectCycle(startNode, -1, visited, adj)){
        cout << "Cycle detected" << endl;
    }
    else{
        cout << "No Cycle detected" << endl;
    }

    return 0;
}