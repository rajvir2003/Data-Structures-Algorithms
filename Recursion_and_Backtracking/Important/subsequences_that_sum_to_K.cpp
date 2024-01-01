#include<bits/stdc++.h>
using namespace std;

void subsequences(int arr[], int index, int sum, int k, vector<int> &v, int n){
    if(index == n){
        if(sum == k){
            for(auto it: v) cout << it << " ";
            cout << endl;
        }
        return;
    }
    v.push_back(arr[index]);
    sum += arr[index];
    subsequences(arr, index+1, sum, k, v, n);
    sum -= arr[index];
    v.pop_back();
    subsequences(arr, index+1, sum, k, v, n);
}

int main(){
    int arr[] = {13,12,14,6,12,7,3,3,13};
    int n = 9;
    int k = 48;
    int sum = 0;
    vector<int> v;
    subsequences(arr, 0, sum, k, v, n);

    return 0;
}