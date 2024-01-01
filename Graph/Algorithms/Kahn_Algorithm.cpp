#include<bits/stdc++.h>
using namespace std;

/* Topological sort using BFS is also known as Kahn's Algorithm */

vector<int> topologicalSort(map<int, list<int>> adj){
    // storing the indegrees of the nodes
    map<int, int> indegree;
    for(auto i: adj){
        for(auto neighbour: i.second){
            indegree[neighbour]++;
        }
    }

    // push nodes who have their indegree as 0
    queue<int> q;
    for(auto it: adj){
        if(indegree[it.first] == 0){
            q.push(it.first);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto neighbour: adj[node]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return topo;
}

int main(){
    map<int, list<int>> adj;
    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0,1};
    adj[5] = {0,2};

    vector<int> topo = topologicalSort(adj);

    for(auto it: topo){
        cout << it << " ";
    } cout << endl;

    return 0;
}