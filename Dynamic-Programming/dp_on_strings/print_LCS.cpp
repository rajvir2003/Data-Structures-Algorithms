#include<bits/stdc++.h>
using namespace std;

string LCS(string &s1, string &s2){
    int n = s1.length();
    int m = s2.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    for(auto i: dp){
        for(auto j: i){
            cout << j << " ";
        } cout << endl;
    }

    int i = n;
    int j = m;
    string ans = "";
    for(int i = 0; i < dp[n][m]; i++) ans += "$";
    int index = dp[n][m]-1;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans[index--] = s1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    return ans;
}

int main(){
    string s1 = "abcde";
    string s2 = "ace";
    string ans = LCS(s1, s2);
    cout << "Longest Common Substring: " << ans << endl;

    return 0;
}