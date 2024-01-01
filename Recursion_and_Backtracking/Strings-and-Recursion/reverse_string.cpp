#include<bits/stdc++.h>
using namespace std;

void reverse(string& str, int i, int j){
    // base condition
    if(i > j){
        return;
    }
    else{
        swap(str[i], str[j]);
        // recursive call
        reverse(str, i+1, j-1);
    }
}

int main(){
    string s = "abcde";
    int n = s.length();
    
    reverse(s, 0, n-1);
    cout << s << endl;

    return 0;
}