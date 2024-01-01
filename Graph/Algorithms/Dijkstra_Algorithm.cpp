#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<pair<int,int>> adj[], int N, int src){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0, src});
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWeight = it.second;
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main(){
    int N = 6;
    vector<pair<int,int>> adj[N];
    adj[0] = {{1,4}, {2,4}};
    adj[1] = {{0,4}, {2,2}};
    adj[2] = {{0,4}, {1,2}, {3,3}, {4,1}, {5,6}};
    adj[3] = {{2,3}, {5,2}};
    adj[4] = {{2,1}, {5,3}};
    adj[5] = {{2,6}, {3,2}, {4,3}};

    int src = 0;
    vector<int> dist = dijkstra(adj, N, src);

    for(auto it: dist){
        cout << it << " ";
    } cout << endl;

    return 0;
}