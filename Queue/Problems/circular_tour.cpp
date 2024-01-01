#include<bits/stdc++.h>
using namespace std;

int tour(vector<pair<int,int>> p, int n){
    // p.first = petrol
    // p.second = distance

    int start = 0;
    int balance = 0;
    int deficit = 0;

    for(int i = 0; i < n; i++){
        balance += p[i].first - p[i].second;

        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(balance + deficit >= 0){
        return start;
    }
    return -1;
}

int main(){
    vector<pair<int,int>> p = {{4,6},{6,5},{7,3},{4,5}};
    int n = p.size();
    
    int startIndex = tour(p, n);
    
    if(startIndex >= 0){
        cout << "Tour starts from index " << startIndex << endl;
    }
    else{
        cout << "Tour not possible" << endl;
    }

    return 0;
}