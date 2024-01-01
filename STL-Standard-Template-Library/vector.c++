#include<bits/stdc++.h>
using namespace std;

int main(){
    // initializing the vector
    vector <int> v; // creates an empty vector
    cout << "size of vector before inserting: " << v.size() << endl;
    vector <int> v1 = {5,100}; // creates {100,100,100,100,100}
    vector <pair<int, int>> vp = {{2,3},{4,6},{7,8}};  // vector of pairs
    
    // pushing elements in vector
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(2);
    v.push_back(0);
    // inserting at specific position
    v.insert(v.begin(),20); // inserts 20 at first position
    cout << "size of vector after inserting: " << v.size() << endl;

    // deleting elements from vector
    v.pop_back();
    v.pop_back();
    cout << "size of vector after deleting 2 elements: " << v.size() << endl;

    // displaying the first and last(back) element of vector
    cout << "first element is " << v.front() << endl;
    cout << "last element is " << v.back() << endl;

    // checking if vector is empty or not
    cout << "Empty or not -> " << v.empty() << endl;

    // copying elements of v to v2
    vector<int> v2(v);

    // printing elements of v2
    for(auto i: v2){
        cout << i << " ";
    }
    cout << endl;

    for(auto it = v2.begin(); it != v2.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    // accessing random elements from vector with index
    cout << "value at index 1 is " << v2.at(1) << endl;


    v.erase(v.begin(), v.begin()+2); 
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;
    cout << v.size();

    // clearing an entire vector
    v.clear();

    return 0;
}