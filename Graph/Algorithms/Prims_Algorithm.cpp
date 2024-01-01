#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> minimumSpanningTree(vector<pair<int,int>> adj[], int N){
    vector<pair<int,int>> mst;
    vector<int> visited(N,0);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
    pq.push({0,0,-1});
    
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it[0];
        int node = it[1];
        int parent = it[2];

        if(!visited[node]){
            visited[node] = 1;
            if(parent != -1) mst.push_back({parent,node});
            sum += wt;
        }
        else{continue;}

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;
            if(!visited[adjNode]){
                pq.push({edgeWeight, adjNode, node});
            }
        }
    }
    cout << "Sum of MST = " << sum << endl;
    return mst;
}

int main(){
    int N = 5;
    vector<pair<int,int>> adj[N];
    adj[0] = {{1,2}, {2,1}};
    adj[1] = {{0,2}, {2,1}};
    adj[2] = {{0,1}, {1,1}, {3,2}, {4,2}};
    adj[3] = {{2,2}, {4,1}};
    adj[4] = {{2,2}, {3,1}};

    vector<pair<int,int>> MST = minimumSpanningTree(adj, N);

    for(auto it: MST){
        cout << "[" << it.first << "," << it.second << "]  ";
    } cout << endl;

    return 0;
}