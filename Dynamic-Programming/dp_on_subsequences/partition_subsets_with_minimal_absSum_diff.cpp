#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDiff(vector<int> &arr, int n){
    int sum = 0;
    for(auto it: arr) sum += it;

    vector<vector<bool>> dp(n, vector<bool>(sum+1,false));
    for(int ind = 0; ind < n; ind++) dp[ind][0] = true;
    if(arr[0] <= sum) dp[0][arr[0]] = true;
    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= sum; target++){
            bool pick = false;
            if(arr[ind] <= target) pick = dp[ind-1][target-arr[ind]];
            bool notPick = dp[ind-1][target];
            dp[ind][target] = pick | notPick;
        }
    }
    
    int mini = INT_MAX;
    for(int target = 0; target <= sum; target++){
        if(dp[n-1][target] == true){
            int s1 = target;
            int s2 = sum-s1;
            mini = min(mini, abs(s1-s2));
        }
    }

    return mini;
}

int main(){
    vector<int> arr = {3,2,7};
    int n = arr.size();
    int ans = minSubsetSumDiff(arr, n);
    cout << "Minimum absolute subset sum difference is " << ans << endl;

    return 0;
}