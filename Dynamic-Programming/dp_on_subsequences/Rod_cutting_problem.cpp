#include<bits/stdc++.h>
using namespace std;

int f(int ind, int length, int price[], vector<vector<int>> &dp){
    if(ind == 0) {
        if(length >= 1) return price[0]*length;
        return 0;
    }
    if(dp[ind][length] != -1) return dp[ind][length];
    int take = 0;
    if(ind+1 <= length) take = price[ind] + f(ind, length-(ind+1), price, dp);
    int notTake = f(ind-1, length, price, dp);
    return dp[ind][length] = max(take, notTake);
}

int cutRod(int price[], int n) {
    // vector<vector<int>> dp(n, vector<int>(n+1,-1));
    // return f(n-1, n, price, dp);

    // tabulation + space optimization
    vector<int> curr(n+1,0);
    for(int length = 1; length <= n; length++){
        curr[length] = price[0]*length;
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int length = 0; length <= n; length++){
            int take = 0;
            if(ind+1 <= length) take = price[ind] + curr[length-(ind+1)];
            int notTake = curr[length];
            curr[length] = max(take, notTake);
        }
    }
    return curr[n];
}

int main(){
    int n = 8;
    int price[] = {3,5,8,9,10,17,17,20};

    int ans = cutRod(price, n);
    cout << "Maximum price by cutting rod: " << ans << endl;
    
    return 0;
}