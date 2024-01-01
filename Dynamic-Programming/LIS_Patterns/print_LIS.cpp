#include<bits/stdc++.h>
using namespace std;

vector<int> LIS(vector<int> &nums, int n){
    vector<int> dp(n,1), hash(n);
    for(int i = 0; i < n; i++) hash[i] = i;

    int ind = 0;
    int maxi = 1;

    for(int i = 0; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && dp[i] < dp[prev]+1){
                dp[i] = dp[prev]+1;
                hash[i] = prev;
            }
        }
        if(maxi < dp[i]){
            maxi = dp[i];
            ind = i;
        }
    }

    vector<int> ans;
    ans.push_back(nums[ind]);

    while(hash[ind] != ind){
        ind = hash[ind];
        ans.push_back(nums[ind]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> nums = {5,4,11,1,16,8};
    int n = nums.size();
    vector<int> res = LIS(nums, n);
    cout << "Printing LIS: ";
    for(auto it: res){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}