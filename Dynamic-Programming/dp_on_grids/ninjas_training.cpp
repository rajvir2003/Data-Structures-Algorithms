#include<bits/stdc++.h>
using namespace std;

// with memoization
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for(int task = 0; task < 3; task++){
        if(last != task){
            int pts = points[day][task] + f(day-1, task, points, dp);
            maxi = max(maxi, pts);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,0);
    // vector<vector<int>> dp(n, vector<int>(4,-1));
    // return f(n-1, 3, points, dp);
    
    // with tabulation 
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++){
        vector<int> temp(4,0);
        for(int last = 0; last < 4; last++){
            for(int task = 0; task < 3; task++){
                if(task != last){
                    int pts = points[day][task] + prev[task];
                    temp[last] = max(temp[last], pts);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

int main(){
    vector<vector<int>> points = {
        {18,11,19},
        {4,13,7},
        {1,8,13}
    };
    int n = points.size();
    int ans = ninjaTraining(n, points);

    cout << "Answer: " << ans << endl;
    
    return 0;
}