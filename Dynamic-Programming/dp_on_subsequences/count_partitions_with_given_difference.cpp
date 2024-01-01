#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
// memoization
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target < 0) return 0;
    if(ind < 0) return target == 0;
    
    if(dp[ind][target] != -1) return dp[ind][target];
    int pick = f(ind-1, target-arr[ind], arr, dp) % mod;
    int notPick = f(ind-1, target, arr, dp) % mod;
    return dp[ind][target] = (pick + notPick) % mod;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int totalSum = 0;
    for(auto it: arr){
        totalSum = (totalSum+it) % mod;
    }
    if((totalSum+d)%2 != 0) return 0;
    
    int target = ((d+totalSum)/2) % mod;
    vector<vector<int>> dp(n, vector<int>(target+1,-1));
    return f(n-1, target, arr, dp);
}

int main(){
    vector<int> arr = {5,2,6,4};
    int d = 3;
    int n = arr.size();
    int ans = countPartitions(n, d, arr);
    cout << "Partitions with difference of " << d << ": " << ans << endl;
    
    return 0;
}