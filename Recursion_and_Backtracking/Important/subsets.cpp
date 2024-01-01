#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, vector<int> output, vector<vector<int>>& ans){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // exclude part
    solve(nums, index+1, output, ans);

    // include part
    output.push_back(nums[index]);
    solve(nums, index+1, output, ans);
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, index, output, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << " ";
    }
    
    return 0;
}