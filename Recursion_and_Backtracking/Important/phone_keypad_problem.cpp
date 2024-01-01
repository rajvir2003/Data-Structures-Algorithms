#include<bits/stdc++.h>
using namespace std;

void solve(string digits, int index, string output, vector<string>& ans, string map[]){
    // base case
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }

    int num = digits[index] - '0';
    string value = map[num];
    for(int i = 0; i < value.length(); i++){
        output.push_back(value[i]);
        solve(digits, index+1, output, ans, map);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length() < 1){
        return ans;
    }
    string output = "";
    int index = 0;
    string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
                    "tuv", "wxyz"};
    solve(digits, index, output, ans, map);
    return ans;
}

int main(){
    string digits = {"23"};
    vector<string> answer = letterCombinations(digits);
    for(auto i : answer){
        cout << i << " ";
    }
    
    return 0;
}