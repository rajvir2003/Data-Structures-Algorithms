#include<bits/stdc++.h>
using namespace std;

int f(string &s1, string &s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int minOperations(string &s1, string &s2){
    int lcs = f(s1, s2);
    int deletions = s1.length() - lcs;
    int insertions = s2.length() - lcs;
    return deletions + insertions;
}

int main(){
    string s1 = "abcd";
    string s2 = "anc";
    int ans = minOperations(s1, s2);
    cout << "Minimum operations to make s1 equal to s2: " << ans << endl;

    return 0;
}