#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int i, int j){
    // base condition
    if(i > j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }

    return isPalindrome(str, i+1, j-1);
}

int main(){
    string str = "racecar";
    int n = str.length();

    if(isPalindrome(str, 0, n-1)){
        cout << "String is a palindrome" << endl;
    }
    else{
        cout << "String is not a palindrome" << endl;
    }

    return 0;
}