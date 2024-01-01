#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int prev_ind, vector<int> &nums, int n, vector<vector<int>> &dp){
    if(ind == n) return 0;
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

    int pick = 0;
    if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
        pick = 1 + f(ind+1, ind, nums, n, dp);
    }
    int notPick = f(ind+1, prev_ind, nums, n, dp);
    return dp[ind][prev_ind+1] = max(pick, notPick);
}

int lengthOfLIS(vector<int> &nums, int n){
    // vector<vector<int>> dp(n, vector<int>(n,-1));
    // return f(0, -1, nums, n, dp);

    // tabulation (method-1)
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int ind = n-1; ind >= 0; ind--){
        for(int prev_ind = -1; prev_ind <= ind-1; prev_ind++){
            int pick = 0;
            if(prev_ind == -1 || nums[ind] > nums[prev_ind]) pick = 1 + dp[ind+1][ind+1];
            int notPick = dp[ind+1][prev_ind+1];
            dp[ind][prev_ind+1] = max(pick, notPick);
        }
    }
    return dp[0][0];
}

// tabulation (method-2)
int lengthOfLIS_2(vector<int> &nums, int n){
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i = 0; i < n; i++){
        for(int prev = 0; prev <= i-1; prev++){
            if(nums[prev] < nums[i]){
                dp[i] = max(dp[i], dp[prev]+1);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

// using binary search
int LIS_using_binarySearch(vector<int> &nums, int n){
    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i = 1; i < n; i++){
        if(temp.back() < nums[i]){
            temp.push_back(nums[i]);
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return temp.size();
}

int main(){
    vector<int> nums = {1,7,8,4,5,6,-1,9};
    int n = nums.size();
    int len = LIS_using_binarySearch(nums, n);
    cout << "Length of Longest Increasing Subsequence: " << len << endl;

    return 0;
}