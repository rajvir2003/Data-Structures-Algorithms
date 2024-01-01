#include<bits/stdc++.h>
using namespace std;

int main(){
    // initializing an empty list l
    list <int> l;

    l.push_back(12);
    l.push_back(2);
    l.push_back(67);
    l.push_back(38);
    l.push_front(15);
    l.push_front(10);

    // copying elements of list l to list l1
    list <int> l1(l);

    // deleting elements of list 
    l.pop_back();

    for(auto i: l) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Size of list is " << l.size() << endl;

    // erasing an entire list
    l.erase(l.begin(), l.end());
    cout << "After erase : " << endl;
    for(auto i: l) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}