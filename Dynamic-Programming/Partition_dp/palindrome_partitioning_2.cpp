#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int s, int e, string &str){
    while(s < e){
        if(str[s++] != str[e--]) return false;
    }
    return true;
}

// memoization
int f(int i, int n, string &str, vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];

    int mini = INT_MAX;
    for(int ind = i; ind < n; ind++){
        if(isPalindrome(i,ind,str)){
            int cost = 1 + f(ind+1, n, str, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}

int minCut(string &str){
    int n = str.length();
    // vector<int> dp(n, -1);
    // return f(0, n, str, dp) - 1;

    // tabulation
    vector<int> dp(n+1, 0);
    dp[n] = 0;
    
    for(int i = n-1; i >= 0; i--){
        int mini = INT_MAX;
        for(int ind = i; ind < n; ind++){
            if(isPalindrome(i,ind,str)){
                int cost = 1 + dp[ind+1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }
    return dp[0]-1;
}

int main(){
    string str = "bababcbadcede";
    int ans = minCut(str);
    cout << "Minimum cuts to make all substrings palindrome: " << ans << endl;
    return 0;
}