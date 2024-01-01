#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, int &maxi){
    if(i == 0 || j == 0){
        return 0;
    }
    if(s1[i-1] == s2[j-1]){
        dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp,maxi);
        maxi = max(maxi, dp[i][j]);
    }
    else{
        dp[i][j] = 0;
        f(i-1,j,s1,s2,dp,maxi);
        f(i,j-1,s1,s2,dp,maxi);
        maxi = max(maxi,dp[i][j]);
    }
    return dp[i][j];
}

int longestCommonSubstring(string &s1, string &s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    int maxi = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi, dp[i][j]);
            }
        }
    }
    return maxi;
}

int main(){
    string s1 = "abcjklpwq";
    string s2 = "acjklpwd";
    // int ans = longestCommonSubstring(s1, s2);
    int maxi = 0;
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
    int a = f(s1.length(),s2.length(),s1,s2,dp,maxi);
    cout << "length of longest common substring: " << maxi << endl;

    return 0;
}