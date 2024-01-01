#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i == 0) return j;
    if(j == 0) return i;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j] = f(i-1, j-1, s1, s2, dp);
    return dp[i][j] = 1 + min(f(i-1, j, s1, s2, dp), min(f(i, j-1, s1, s2, dp), f(i-1, j-1, s1, s2, dp)));
}

int minimum_operations(string &s1, string &s2){
    int n = s1.length();
    int m = s2.length();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return f(n, m, s1, s2, dp);

    // tabulation + space optimization
    vector<int> prev(m+1,0), curr(m+1,0);
    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++){
        curr[0] = i;
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
            else curr[j] = 1 + min(prev[j], min(curr[j-1],prev[j-1]));
        }
        prev = curr;
    }
    return prev[m];
}

int main(){
    string word1 = "horse";
    string word2 = "ros";
    int ans = minimum_operations(word1, word2);
    cout << "Minimum operations to convert s1 to s2: " << ans << endl;

    return 0;
}