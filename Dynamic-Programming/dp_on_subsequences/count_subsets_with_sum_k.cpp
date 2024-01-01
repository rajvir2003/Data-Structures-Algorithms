#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp){
    if(sum < 0) return 0;
    if(ind < 0) return sum == 0;

    if(dp[ind][sum] != -1) return dp[ind][sum];
    int pick = f(ind-1, sum-arr[ind], arr, dp);
    int notPick = f(ind-1, sum, arr, dp);
    return dp[ind][sum] = pick + notPick;
}

int countSubsets(vector<int> &arr, int k){
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(k+1,-1));
    // return f(n-1, k, arr, dp);

    // tabulation + space optimization
    vector<int> prev(k+1,0), curr(k+1,0);
    prev[0] = 1;
    for(int ind = 0; ind < n; ind++){
        for(int target = 0; target <= k; target++){
            int pick = 0;
            if(target-arr[ind] >= 0) pick = prev[target-arr[ind]];
            int notPick = prev[target];
            curr[target] = pick + notPick;
        }
        prev = curr;
    } 
    return prev[k];
}

int main(){
    vector<int> arr = {9,7,0,3,9,8,6,5,7,6};
    int k = 31;
    int ans = countSubsets(arr, k);
    cout << "Total subsets with sum " << k << " are: " << ans << endl;

    return 0;
}