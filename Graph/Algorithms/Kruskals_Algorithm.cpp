#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
    vector<int> parent;
    vector<int> size;

    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) 
            parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void Union(int u, int v){
        int ultPar_u = findParent(u);
        int ultPar_v = findParent(v);
        if(ultPar_u == ultPar_v) return;

        if(size[ultPar_u] < size[ultPar_v]){
            parent[ultPar_u] = ultPar_v;
            size[ultPar_v] += size[ultPar_u];
        }
        else{
            parent[ultPar_v] = ultPar_u;
            size[ultPar_u] += size[ultPar_v];
        }
    }
};

int main(){
    vector<vector<int>> edges;
    edges.push_back({5,3,4});
    edges.push_back({8,3,6});
    edges.push_back({3,2,3});
    edges.push_back({4,1,5});
    edges.push_back({2,1,2});
    edges.push_back({9,4,5});
    edges.push_back({3,2,4});
    edges.push_back({7,2,6});
    edges.push_back({1,1,4});

    int n = 6;
    DisjointSet g(n);

    sort(edges.begin(), edges.end());
    vector<pair<int,int>> MST;

    int ans = 0;
    for(auto it: edges){
        int wt = it[0];
        int u = it[1];
        int v = it[2];

        if(g.findParent(u) != g.findParent(v)){
            g.Union(u,v);
            MST.push_back({u,v});
            ans += wt;
        }
    }

    cout << "MST:  ";
    for(auto it: MST){
        cout << "[" << it.first << "," << it.second << "] "; 
    }
    cout << endl;
    cout << "Total weight = " << ans << endl;

    return 0;
}