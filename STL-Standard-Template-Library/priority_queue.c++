#include<bits/stdc++.h>
using namespace std;

int main(){
    // max heap 
    priority_queue <int> maxi;  
    maxi.push(35);
    maxi.push(20);
    maxi.push(52);
    maxi.push(34);

    cout << "Elements of max heap: ";
    int m = maxi.size();
    for (int i = 0; i < m; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;
    
    cout << "Empty or not -> " << maxi.empty() << endl;
    // cout << maxi.top() << endl;
    // maxi.pop();  // removes the maximum element from the priority queue
    // cout << maxi.top() << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;
    mini.push(10);
    mini.push(5);
    mini.push(8);
    mini.push(9);
    mini.push(2);

    cout << "Elements of min heap: ";
    int n = mini.size();
    for(int i = 0; i < n; i++) {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    cout << "Empty or not -> " << mini.empty() << endl;

    // cout << mini.top() << endl;
    // mini.pop();  // removes the minimum element from the priority queue
    // cout << mini.top() << endl;
    return 0;
}