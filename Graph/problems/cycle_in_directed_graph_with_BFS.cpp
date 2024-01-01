#include<bits/stdc++.h>
using namespace std;

// using Kahn's algorithm
bool detectCycle(unordered_map<int, list<int>> adj, int totalNodes){
    map<int, int> indegree;
    for(auto it: adj){
        for(auto neighbour: it.second){
            indegree[neighbour]++;
        }
    }

    queue<int> q;
    for(auto it: adj){
        if(indegree[it.first] == 0){
            q.push(it.first);
        }
    }

    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;

        for(auto neighbour: adj[node]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    if(count == totalNodes) return false;
    else return true;
}

int main(){
    unordered_map<int, list<int>> adj;
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4,5};
    adj[4] = {2};
    adj[5] = {};
    int V = adj.size();

    if(detectCycle(adj, V)){
        cout << "Cycle is Detected" << endl;
    }
    else{
        cout << "No cycle is detected" << endl;
    }

    return 0;
}