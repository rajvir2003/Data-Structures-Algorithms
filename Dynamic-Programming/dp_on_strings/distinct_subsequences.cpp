#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(j == 0) return 1;
    if(i == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]){
        return dp[i][j] = f(i-1, j-1, s1, s2, dp) + f(i-1, j, s1, s2, dp);
    }
    return dp[i][j] = f(i-1, j, s1, s2, dp);
}

int numDistinct(string &s1, string &s2){
    int n = s1.length();
    int m = s2.length();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return f(n, m, s1, s2, dp);

    // tabulation + single array optimization
    vector<int> dp(m+1,0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = m; j > 0; j--){
            if(s1[i-1] == s2[j-1]){
                dp[j] = dp[j-1] + dp[j];
            }
        }
    }
    return dp[m];
}

int main(){
    string s1 = "babgbag";
    string s2 = "bag";
    int ans = numDistinct(s1, s2);
    cout << "The number of times s2 appears in s1: " << ans << endl;

    return 0;
}