#include<bits/stdc++.h>
using namespace std;

// memoization
int lcs(int i, int j, string s1, string s2, vector<vector<int>> &dp){
    if(i == 0 || j == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + lcs(i-1, j-1, s1, s2, dp);
    return dp[i][j] = max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));
}

int longestPalindromicSubsequence(string &str){
    string temp = str;
    reverse(temp.begin(),temp.end());
    int n = str.length();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return lcs(n,n,str,temp,dp);

    // tabulation
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(str[i-1] == temp[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main(){
    string str = "bbabcbcab";
    int ans = longestPalindromicSubsequence(str);
    cout << "Answer: " << ans << endl;

    return 0;
}