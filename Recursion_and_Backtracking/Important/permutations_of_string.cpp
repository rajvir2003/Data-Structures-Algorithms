#include<bits/stdc++.h>
using namespace std;

void solve(string str, int index, vector<string> &ans) {
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for(int i = index; i < str.length(); i++){
        swap(str[index], str[i]);
        solve(str, index+1, ans);
    }
}

vector<string> Permutations(string &str)
{
    vector<string> ans;
    sort(str.begin(), str.end());
    int index = 0;
    solve(str, index, ans);
    return ans;
}

int main(){
    string str = "abc";
    vector<string> result = Permutations(str);
    
    for(auto i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}