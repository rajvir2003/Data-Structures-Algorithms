#include<bits/stdc++.h>
using namespace std;

bool isPresent(vector<int> &nums, int k){
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(k+1,false));
    for(int ind = 0; ind < n; ind++) dp[ind][0] = true;
    if(nums[0] <= k) dp[0][nums[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= k; target++){
            bool pick = false;
            if(nums[ind] <= target) pick = dp[ind-1][target-nums[ind]];
            bool notPick = dp[ind-1][target];
            dp[ind][target] = pick | notPick;
        }
    }
    return dp[n-1][k];
}

bool canPartition(vector<int>& nums){
    int sum = 0;
    for(auto it: nums) sum += it;
    if(sum%2 != 0) return false;
    else isPresent(nums, sum/2);
}

int main(){
    vector<int> nums = {1,5,11,5};
    if(canPartition(nums)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}