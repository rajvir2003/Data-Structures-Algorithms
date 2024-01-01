#include<bits/stdc++.h>
using namespace std;

void printReverse(string v){
    reverse(v.begin(),v.end());
    cout << v;
}

void reverseString(string s) {
    string v = "";
    int i = 0;
    while(i <= s.length()){
        if(s[i] == 32){
            printReverse(v);
            cout << " ";
            v.clear();
        }
        else{
            v.push_back(s[i]);
        }
        i++;
    }
    printReverse(v);
}

int main(){
    char s[30];
    cout << "Enter string: ";
    gets(s);

    reverseString(s);


    return 0;
}