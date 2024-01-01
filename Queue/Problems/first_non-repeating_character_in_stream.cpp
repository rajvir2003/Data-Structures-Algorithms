#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string s){
    map<char, int> count;
    queue<char> q;
    string ans = "";

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        count[ch]++; // increase the count of character
        q.push(ch); // push character in queue

        // push first non-repeating character into string(ans)
        while(!q.empty()){
            if(count[q.front()] > 1){ // remove repeating elements
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        // if no non-repeating element exist in queue then push '#' in string
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string s = "aabc";
    string ans = FirstNonRepeating(s);
    cout << ans << endl;

    return 0;
}