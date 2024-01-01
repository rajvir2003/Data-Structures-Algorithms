#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int src, vector<int> adj[], int N){
    vector<int> ans(N,-1);
    unordered_map<int, bool> visited;
    queue<pair<int,int>> q;
    q.push({src, 0});
    visited[src] = true;

    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        ans[node] = dist;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push({neighbour, dist+1});
            }
        }
    }

    return ans;
}

int main(){
    int N = 9;
    vector<int> adj[N];
    adj[0] = {1,3};
    adj[1] = {0,2};
    adj[2] = {1,6};
    adj[3] = {0,4};
    adj[4] = {3,5};
    adj[5] = {4,6};
    adj[6] = {2,5,7,8};
    adj[7] = {6,8};
    adj[8] = {6,7};

    int src = 0;

    vector<int> ans = shortestPath(src, adj, N);
    for(int i = 0; i < ans.size(); i++){
        cout << "Distance from " << src << " to " << i << " : " << ans[i] << endl;
    }

    return 0;
}