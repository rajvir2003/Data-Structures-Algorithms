#include<bits/stdc++.h>
using namespace std;

int f(string &s1, string &s2, int n, int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    // printing shortest common supersequence
    int i = n;
    int j = m;
    string scs = "";
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            scs += s1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            scs += s1[i-1];
            i--;
        }
        else{
            scs += s2[j-1];
            j--;
        }
    }
    while(i > 0){
        scs += s1[i-1];
        i--;
    }
    while(j > 0){
        scs += s2[j-1];
        j--;
    }
    reverse(scs.begin(),scs.end());
    cout << "shortest common supersequence: " << scs << endl;
    
    return dp[n][m];
}

int shortestCommonSupersequence(string &s1, string &s2, int n, int m){
    int lcs = f(s1, s2, n, m);
    // returns the length of shortest common supersequence
    return lcs + (n-lcs) + (m-lcs);
}

int main(){
    string s1 = "brute";
    string s2 = "groot";
    int n = s1.length();
    int m = s2.length();
    int scs = shortestCommonSupersequence(s1,s2,n,m);
    cout << "length of shortest common Supersequence: " << scs << endl;

    return 0;
}