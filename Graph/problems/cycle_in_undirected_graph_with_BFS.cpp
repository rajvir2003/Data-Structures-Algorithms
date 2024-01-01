#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int startNode, unordered_map<int, list<int>> &adj){
    unordered_map<int, bool> visited;
    queue<pair<int, int>> q;
    q.push({startNode, -1});
    visited[startNode] = true;

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push({it, node});
            }
            else if(parent != it){
                return true;
            }
        }
    }
    return false;
}

int main(){
    unordered_map<int, list<int>> adj;
    adj[1] = {2,4};
    adj[2] = {1,3};
    adj[3] = {2,6};
    adj[4] = {1,7,5};
    adj[5] = {4,6};
    adj[6] = {3,5};
    adj[7] = {4};

    int startNode = 1;

    if(detectCycle(startNode, adj)){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle Detected" << endl;
    }

    return 0;
}