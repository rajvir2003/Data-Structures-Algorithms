#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums, int n){
    sort(nums.begin(),nums.end());
    vector<int> dp(n,1), hash(n);
    int maxi = 1;
    int ind = 0;

    for(int i = 1; i < n; i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(nums[i] % nums[prev] == 0 && dp[i] < dp[prev]+1){
                dp[i] = dp[prev]+1;
                hash[i] = prev;
            }
        }
        if(maxi < dp[i]){
            maxi = dp[i];
            ind = i;
        }
    }

    vector<int> res;
    res.push_back(nums[ind]);
    while(hash[ind] != ind){
        ind = hash[ind];
        res.push_back(nums[ind]);
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    vector<int> nums = {1,16,7,8,4};
    int n = nums.size();
    vector<int> res = largestDivisibleSubset(nums, n);
    cout << "Largest Divisible Subset: ";
    for(auto it : res){
        cout << it << " ";
    } cout << endl;

    return 0;
}