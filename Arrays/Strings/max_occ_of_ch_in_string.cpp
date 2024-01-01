#include<bits/stdc++.h>
using namespace std;

char getMaxOcc(string s) {
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int number = s[i] - 'a';
        arr[number]++;
    }

    int max = -1; 
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if(max < arr[i]){
            max = arr[i];
            ans = i;
        }
    } 
    return ans + 'a';
}

int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;

    char ans = getMaxOcc(s);
    cout << "Max Occurance: " << ans << endl;

    return 0;
}