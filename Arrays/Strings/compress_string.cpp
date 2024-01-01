#include<bits/stdc++.h>
using namespace std;

 int compress(vector<char>& chars) {
        int i = 0;
        int n = chars.size();
        int ansIndex = 0;
        while(i < n){
            int j = i+1;
            while(j < n && chars[j] == chars[i]){
                j++;
            }
            // store the character
            chars[ansIndex++] = chars[i];

            int count = j-i;
            if(count > 1){
                // convert count to char for storing single digits( eg: 12 -> '1','2') in answer
                string str = to_string(count);
                // store the count 
                for(char ch : str){
                    chars[ansIndex++] = ch;
                }
            }
            i = j;
        }
        return ansIndex;
    }

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int ans = compress(chars);

    cout << "Size of vector is " << ans << endl;
    for (auto it = chars.begin(); it != chars.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    return 0;
}