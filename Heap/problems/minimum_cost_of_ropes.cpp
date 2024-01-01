#include<bits/stdc++.h>
using namespace std;
// note* - cost of connecting two ropes is sum of their lengths
int minCost(int ropes[], int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++){
        pq.push(ropes[i]);
    }

    int cost = 0;
    while(pq.size() > 1){
        int r1 = pq.top();
        pq.pop();
        int r2 = pq.top();
        pq.pop();

        int sum = r1 + r2;
        pq.push(sum);
        cost += sum;
    }
    return cost;
}

int main(){
    int ropes[] = {4,3,2,6}; // length of ropes
    int n = sizeof(ropes)/sizeof(int);
    int ans = minCost(ropes, n);
    cout << "Minimum cost to connect all ropes is " << ans << endl;
    return 0;
}