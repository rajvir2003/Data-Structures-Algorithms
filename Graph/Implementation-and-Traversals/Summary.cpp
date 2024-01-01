#include<bits/stdc++.h>
using namespace std;

template <typename T>
class graph{
    private:
    int n;
    int m;
    unordered_map<T,list<T>> adjList;

    public:
    graph(int nodes, int edges){
        n = nodes;
        m = edges;
    }

    void addEdges(bool direction){
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            if(!direction){
                adjList[v].push_back(u);
            }
        }
    }

    void bfs(T node){
        unordered_map<T,bool> visited;
        queue<T> q;
        q.push(node);
        visited[node] = true;
        cout << "Printing bfs: " << endl;
        while(!q.empty()){
            T temp = q.front();
            q.pop();
            cout << temp << " ";
            
            for(auto it: adjList[temp]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        cout << endl;
    }

    void dfs(T node, unordered_map<T,bool> &visited){
        cout << node << " ";
        visited[node] = true;

        for(auto it: adjList[node]){
            if(!visited[it]){
                dfs(it, visited);
            }
        }
    }

    void print_Adjacency_List(){
        cout << "Printing Adjacency List: " << endl;
        for(auto i: adjList){
            cout << i.first << " -> ";
            for(auto j: i.second){
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

    graph<int> g(n,m);
    g.addEdges(0);
    g.print_Adjacency_List();
    g.bfs(6);
    unordered_map<int,bool> visited;
    cout << "Printing dfs: " << endl;
    g.dfs(3,visited);
    
    return 0;
}