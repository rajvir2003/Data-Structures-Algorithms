#include<bits/stdc++.h>
using namespace std;

int main(){
    map <int, string> m;
    
    m[2] = "Amazon";
    m[7] = "Microsoft";
    m[6] = "Google";
    m[1] = "Apple";
    m[4] = "Samsung";
    m.insert({5,"Facebook"});

    for(auto i: m) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    
    map<int,string> :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " : " << it->second << endl;
    }cout << endl;
    
    m.erase(4);
    
    for(it = m.find(2); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }


    return 0;
}