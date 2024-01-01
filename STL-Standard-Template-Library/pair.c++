#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int, int> p = {1,2};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1,{3,4}};  // nested pair
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;

    pair<int, int> arr[] = {{2,3},{4,1},{5,6}};   // array of pairs
    cout << arr[2].second << endl;

    return 0;
}