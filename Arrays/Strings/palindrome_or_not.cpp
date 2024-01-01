#include<bits/stdc++.h>
using namespace std;

bool valid(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
        return true;
    }
    else{
        return false;
    }
}

char toLowerCase(char ch) {
    if((ch >= 'a' && ch <= 'z') || ch >= '0' && ch <= '9'){
        return ch;
    }
    else{
        ch = ch + 32;
        return ch;
    }
}

bool checkPalindrome(string s){
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }

    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = toLowerCase(temp[i]);
    }
    
    int start = 0;
    int end = temp.length() - 1;

    while(start <= end){
        if(temp[start] != temp[end]){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}

int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Palindrome or not: " << checkPalindrome(s) << endl;

    return 0;
}