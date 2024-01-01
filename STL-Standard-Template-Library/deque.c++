#include<bits/stdc++.h>
using namespace std;

int main(){
    // initializing deque
    deque <int> d; // creates an empty deque

    // checking if deque is empty or not
    cout << "Empty or not -> " << d.empty() << endl;

    // inserting elements in deque
    d.push_back(10);
    d.push_back(8);
    d.push_front(5);
    d.push_front(12);
    d.push_front(3);

    // deleting elements from deque
    d.pop_back();
    d.pop_front();

    // printing elements of deque
    for(auto i: d) {
        cout << i << " ";
    }
    cout << endl;

    // accessing elements with index
    cout << "value at index 1 is " << d.at(1) << endl;
    
    // deleting elements with a given range
    d.erase(d.begin(), d.begin()+2);

    cout << "Printing elements after erase function: " << endl;
    for(auto i: d) {
        cout << i << " ";
    }


    return 0;
}