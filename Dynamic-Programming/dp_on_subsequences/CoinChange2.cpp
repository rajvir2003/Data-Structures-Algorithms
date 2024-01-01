#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
    if(ind == 0){
        return (amount%coins[0] == 0);
    }

    if(dp[ind][amount] != -1) return dp[ind][amount];
    int pick = 0;
    if(amount >= coins[ind]) pick = f(ind, amount-coins[ind], coins, dp);
    int notPick = f(ind-1, amount, coins, dp);
    return dp[ind][amount] = pick + notPick;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    // return f(n-1, amount, coins, dp);

    // tabulation + space optimization
    vector<int> prev(amount+1, 0), curr(amount+1, 0);
    for(int target = 0; target <= amount; target++){
        if(target%coins[0] == 0) prev[target] = 1;
    }

    for(int ind = 1; ind < n; ind++){
        for(int target = 0; target <= amount; target++){
            int pick = 0;
            if(target >= coins[ind]) pick = curr[target-coins[ind]];
            int notPick = prev[target];
            curr[target] = pick + notPick;
        }
        prev = curr;
    }
    return prev[amount];
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;
    
    cout << "Total number of ways to make " << amount << ": " << change(amount,coins) << endl;

    return 0;
}