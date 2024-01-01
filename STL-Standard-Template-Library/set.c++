#include<bits/stdc++.h>
using namespace std;

int main(){
    // set stores UNIQUE elements in a SORTED order
    set <int> s;

    s.insert(5);
    s.insert(5);
    s.insert(3);
    s.insert(8);
    s.insert(1);
    s.insert(9);
    s.insert(8);

    for(auto i: s) {
        cout << i << " ";
    }
    cout << endl;

    // printing elements in a specific range
    for (auto k = s.find(5); k != s.end(); k++)
    {
        cout << *(k) << " ";
    }
    cout << endl;
    

    auto it = s.begin();
    it++;
    s.erase(it);
    for(auto i: s) {
        cout << i << " ";
    }
    cout << endl;

    cout << "8 is present or not -> " << s.count(8) << endl;


    return 0;
}