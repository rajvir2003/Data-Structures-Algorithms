#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

int maxminSum(vector<int> arr, int k){
    deque<int> maxi;
    deque<int> mini;
    int sum = 0;
    // processing first window 
    for(int i = 0; i < k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    sum += arr[maxi.front()] + arr[mini.front()];

    for(int i = k; i < arr.size(); i++){
        // removal
        if(!maxi.empty() && i-maxi.front() >= k){
            maxi.pop_front();
        }
        if(!mini.empty() && i-maxi.front() >= k){
            mini.pop_front();
        }
        // addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        sum += arr[maxi.front()] + arr[mini.front()];
    }

    return sum;
}

int main(){
    vector<int> arr = {2,5,-1,7,-3,-1,-2};
    int windowSize = 4;
    int ans = maxminSum(arr, windowSize);
    cout << ans << endl;

    return 0;
}