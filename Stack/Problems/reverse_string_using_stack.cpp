#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "rajvir";
    stack<char> s;
    cout << "Orignal string: " << str << endl;

    for(int i = 0; i < str.length(); i++){
        s.push(str[i]);
    }

    int i = 0;
    while(!s.empty() && i < str.length()){
        str[i] = s.top();
        s.pop();
        i++;
    }

    cout << "Reversed string: " << str << endl;

    return 0;
}