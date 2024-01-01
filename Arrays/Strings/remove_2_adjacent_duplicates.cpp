#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    string st = "";
    for(int i = 0; i < s.length(); i++){
        if(st.empty()){
            st.push_back(s[i]);
        }
        else if(st.back() == s[i]){
            st.pop_back();
        }
        else{
            st.push_back(s[i]);
        }
    }
    return st;
}

int main(){
    string s = "azxxzy";
    string ans = removeDuplicates(s);
    cout << "Result: " << ans << endl;
    return 0;
}