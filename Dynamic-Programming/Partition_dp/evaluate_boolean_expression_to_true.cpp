#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>> &dp){
    if(i == j){
        if(isTrue) return exp[i] == 'T';
        else return exp[i] == 'F';
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    int ways = 0;
    for(int ind = i+1; ind < j; ind += 2){
        int LT = f(i, ind-1, 1, exp, dp);
        int LF = f(i, ind-1, 0, exp, dp);
        int RT = f(ind+1, j, 1, exp, dp);
        int RF = f(ind+1, j, 0, exp, dp);

        if(exp[ind] == '&'){
            if(isTrue) ways += LT*RT;
            else ways += LF*RT + LT*RF + LF*RF;
        }
        else if(exp[ind] == '|'){
            if(isTrue) ways += LT*RT + LF*RT + LT*RF;
            else ways += LF*RF;
        }
        else{
            if(isTrue) ways += LF*RT + LT*RF;
            else ways += LF*RF + LT*RT;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int countWays(string &exp){
    int n = exp.length();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2,-1)));
    // return f(0, n-1, 1, exp, dp);

    // tabulation
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2,0)));
    for(int i = 0; i < n; i++){
        dp[i][i][0] = (exp[i]=='F');
        dp[i][i][1] = (exp[i]=='T');
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1; j < n; j++){
            for(int isTrue = 0; isTrue < 2; isTrue++){
                int ways = 0;
                for(int ind = i+1; ind < j; ind += 2){
                    int LT = dp[i][ind-1][1];
                    int LF = dp[i][ind-1][0];
                    int RT = dp[ind+1][j][1];
                    int RF = dp[ind+1][j][0];

                    if(exp[ind] == '&'){
                        if(isTrue) ways += LT*RT;
                        else ways += LF*RT + LT*RF + LF*RF;
                    }
                    else if(exp[ind] == '|'){
                        if(isTrue) ways += LT*RT + LF*RT + LT*RF;
                        else ways += LF*RF;
                    }
                    else{
                        if(isTrue) ways += LF*RT + LT*RF;
                        else ways += LF*RF + LT*RT;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n-1][1];
}

int main(){
    string exp = "T^F|T&F^T|F";
    int res = countWays(exp);
    cout << "Ways to evaluate " << exp << " to true: " << res << endl;

    return 0;
}