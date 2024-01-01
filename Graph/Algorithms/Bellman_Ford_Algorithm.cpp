#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_Ford(vector<vector<int>> &edges, int n, int src){
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for(int i = 0; i < n-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check if there is a negative cycle 
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
            return {-1};
        }
    }

    return dist;
}

int main(){
    int n = 6;
    vector<vector<int>> edges;
    edges.push_back({3,2,6});
    edges.push_back({5,3,1});
    edges.push_back({0,1,5});
    edges.push_back({1,5,-3});
    edges.push_back({1,2,-2});
    edges.push_back({3,4,-2});
    edges.push_back({2,4,3});
    int src = 0;

    vector<int> dist = bellman_Ford(edges, n, src);
    for(auto it: dist){
        cout << it << " ";
    } cout << endl;

    return 0;
}