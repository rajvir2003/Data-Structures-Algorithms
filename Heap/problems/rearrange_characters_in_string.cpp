#include<bits/stdc++.h>
using namespace std;

string rearrangeString(string str){
    unordered_map<char,int> mp;
    // store frequency of each character in string
    for(int i = 0; i < str.length(); i++){
        mp[str[i]]++;
    }

    priority_queue<pair<int,char>> pq;
    for(int i = 'a'; i <= 'z'; i++){
        // if character is present in string then store pair of character and its frequency in pq
        if(mp[i] > 0){
            pq.push({mp[i],i});
        }
        // if rearrangement is not possible then return -1
        if(mp[i] > (str.length()+1)/2){
            return "-1";
        }
    }

    string res = "";
    while(pq.size() >= 2){
        // character with max frequency
        pair<int,char> a = pq.top();
        pq.pop();
        // character with second max frequency
        pair<int,char> b = pq.top();
        pq.pop();

        res += a.second;
        res += b.second;
        // reduce the frequency of characters after pushing into result string
        a.first--;
        b.first--;

        if(a.first > 0){
            pq.push(a);
        }
        if(b.first > 0){
            pq.push(b);
        }
    }

    if(!pq.empty()){
        res += pq.top().second;
    }
    return res;
}

int main(){
    string str = "aaabbbbcccd";
    cout << endl << "Input string: " << str << endl;
    string res = rearrangeString(str);
    if(res == "-1"){
        cout << endl << "Not possible to rearrange" << endl;
    }
    else{
        cout << endl << "Resultant string: " << res << endl << endl;
    }

    return 0;
}