#include<bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp){
    if(i == n-1) return triangle[n-1][j];

    if(dp[i][j] != -1) return dp[i][j];
    int down = f(i+1, j, n, triangle, dp);
    int diagonal = f(i+1, j+1, n, triangle, dp);
    return dp[i][j] = triangle[i][j] + min(down, diagonal);
}

int minimumTotal(vector<vector<int>> &triangle){
    int n = triangle.size();
    // vector<vector<int>> dp(n, vector<int>(n,-1));
    // return f(0,0,n,triangle,dp);

    // tabulation + space optimization
    vector<int> front(n,0);

    for(int j = 0; j < n; j++){
        front[j] = triangle[n-1][j];
    }

    vector<int> curr(n,0);
    for(int i = n-2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            int down = front[j];
            int diagonal = front[j+1];
            curr[j] = triangle[i][j] + min(down, diagonal);
        }
        front = curr;
    }
    return front[0];
}

int main(){
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    int ans = minimumTotal(triangle);
    cout << "Minimum path sum from top to bottom: " << ans << endl;

    return 0;
}