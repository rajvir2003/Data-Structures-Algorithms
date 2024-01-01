#include<bits/stdc++.h>
using namespace std;

template <typename T>
class graph{
    private:
    int n;
    int m;
    unordered_map<T, list<T>> adjList;

    public:
    graph(int nodes, int edges){
        n = nodes;
        m = edges;
    } 

    void addEdges(bool direction){
        for(int i = 0; i < m; i++){
            T u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            if(!direction){
                adjList[v].push_back(u);
            }
        }
    }

    void print(){
        for(auto i: adjList){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " ";
            } cout << endl;
        }
    }
    
};

int main(){
    int n, m;
    cout << "Nodes: ";
    cin >> n;
    cout << "Edges: ";
    cin >> m;

    graph<char> g(n,m);
    g.addEdges(0);  // 0 for undirected and 1 for directed graph

    g.print();

    return 0;
}