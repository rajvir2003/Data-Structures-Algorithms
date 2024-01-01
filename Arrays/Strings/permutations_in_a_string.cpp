#include<bits/stdc++.h>
using namespace std;

bool isEqual(int a[26], int b[26]){
    for (int i = 0; i < 26; i++)
    {
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    // character count array
    int count1[26] = {0};
    for(int i = 0; i < s1.length(); i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // traverse s2 string in window of size s1 and compare
    int count2[26] = {0};
    int i = 0;
    int windowSize = s1.length();
    // running for first window
    while(i < windowSize && i < s2.length()) {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if(isEqual(count1, count2)){
        return true;
    }

    // process next window
    while(i < s2.length()){
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i-windowSize];
        index = oldChar - 'a';
        count2[index]--;

        i++;

        if(isEqual(count1, count2)){
            return true;
        }
    }

    return false;
    }

int main(){
    string s1 = "an";
    string s2 = "combination";

    cout << "Permutation exists -> " << checkInclusion(s1,s2) << endl;
    
    return 0;
}