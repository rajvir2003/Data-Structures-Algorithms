#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,1), cnt(n,1);
    int maxi = 1;
    for(int i = 0; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && dp[i] < dp[prev]+1){
                dp[i] = dp[prev]+1;
                cnt[i] = cnt[prev];
            }
            else if(nums[prev] < nums[i] && dp[i] == dp[prev]+1){
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    } 
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(maxi == dp[i]) ans += cnt[i];
    }
    return ans;
}

int main(){
    vector<int> nums = {1,5,4,3,2,6,7,10,9,8};
    int ans = findNumberOfLIS(nums);
    cout << "Total number of LIS: " << ans << endl;
    return 0;
}