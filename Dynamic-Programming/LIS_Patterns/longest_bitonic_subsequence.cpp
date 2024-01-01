#include<bits/stdc++.h>
using namespace std;

int longest_bitonic_Subsequence(vector<int> &nums){
    int n = nums.size();
    vector<int> dp1(n,1), dp2(n,1);

    // increasing
    for(int i = 1; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && dp1[i] < dp1[prev]+1){
                dp1[i] = dp1[prev]+1;
            }
        }
    }
    // decreasing
    for(int i = n-2; i >= 0; i--){
        for(int prev = n-1; prev > i; prev--){
            if(nums[prev] < nums[i] && dp2[i] < dp2[prev]+1){
                dp2[i] = dp2[prev]+1;
            }
        }
    }

    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}

int main(){
    vector<int> nums = {1,11,2,10,4,5,2,1};
    int res = longest_bitonic_Subsequence(nums);
    cout << "Length of longest bitonic subsequence: " << res << endl;

    return 0;
}