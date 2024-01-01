#include<bits/stdc++.h>
using namespace std;

static bool cmp(string &s1, string &s2){
    return s1.length() < s2.length();
}

bool check(string &s1, string &s2){
    if(s2.length()-s1.length() != 1) return false;
    int i = 0;
    int j = 0;
    while(i < s2.length()){
        if(j < s1.length() && s2[i] == s1[j]){
            i++; j++;
        }
        else i++;
    }
    if(i == s2.length() && j == s1.length()) return true;
    return false;
}

int longestStrChain(vector<string> &words){
    sort(words.begin(),words.end(),cmp);
    int n = words.size();
    vector<int> dp(n,1);
    int maxi = 1;

    for(int i = 1; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(check(words[prev],words[i])){
                dp[i] = max(dp[i], dp[prev]+1);
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
}

int main(){
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    int len = longestStrChain(words);
    cout << "Length of Longest string chain: " << len << endl;

    return 0;
}