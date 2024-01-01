#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int profit = 0;
    int mini = prices[0];
    int n = prices.size();
    for(int i = 1; i < n; i++){
        int newProfit = prices[i] - mini;
        profit = max(profit, newProfit);
        mini = min(mini, prices[i]);
    }
    return profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout << "Max profit: " << ans << endl;

    return 0;
}