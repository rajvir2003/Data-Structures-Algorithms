#include<bits/stdc++.h>
using namespace std;

// memoization
bool f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return true;
    if(i == 0 && j > 0) return false;
    if(i > 0 && j == 0){
        for(int it = 1; it <= i; i++){
            if(s1[it-1] != '*') return false;
        }
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
        return dp[i][j] = f(i-1, j-1, s1, s2, dp);
    }
    if(s1[i-1] == '*'){
        return dp[i][j] = f(i-1, j, s1, s2, dp) | f(i, j-1, s1, s2, dp);
    }
    return dp[i][j] = false;
}

bool match(string &s1, string &s2){
    int n = s1.length();
    int m = s2.length();
    // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    // return f(n, m, s1, s2, dp);

    // tabulation 
    vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        if(s1[i-1] == '*') dp[i][0] = true;
        else break;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(s1[i-1] == '*'){
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            }
        }
    } 
    return dp[n][m];
}

int main(){
    string s1 = "ge?ks*";
    string s2 = "geeksforgeeks";
    if(match(s1,s2)) cout << "strings are matching" << endl;
    else cout << "strings are not matching" << endl;

    return 0;
}