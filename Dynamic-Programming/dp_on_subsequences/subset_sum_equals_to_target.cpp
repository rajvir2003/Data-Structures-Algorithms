#include<bits/stdc++.h>
using namespace std;

// memoization
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target;

    if(dp[ind][target] != -1) return dp[ind][target];
    bool pick = false;
    if(arr[ind] <= target) pick = f(ind-1, target-arr[ind], arr, dp);
    bool notPick = f(ind-1, target, arr, dp);

    return dp[ind][target] = pick | notPick;
}

bool isPresent(vector<int> &arr, int k){
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(k+1,-1));
    // return f(n-1, k, arr, dp);

    // tabulation
    vector<vector<bool>> dp(n, vector<bool>(k+1,false));
    for(int ind = 0; ind < n; ind++) dp[ind][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= k; target++){
            bool pick = false;
            if(arr[ind] <= target) pick = dp[ind-1][target-arr[ind]];
            bool notPick = dp[ind-1][target];
            dp[ind][target] = pick | notPick; 
        }
    }
    return dp[n-1][k];
}

int main(){
    vector<int> arr = {2,3,1,1};
    int target = 4;
    bool b = isPresent(arr, target);
    if(b) cout << "Subset sum equal to target is found!" << endl;
    else cout << "Not found!" << endl;

    return 0;
}