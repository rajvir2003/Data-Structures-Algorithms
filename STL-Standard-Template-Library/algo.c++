#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 5;
    int b = 3;
    cout << "minimum element is " << min(a,b) << endl;
    cout << "maximum element is " << max(a,b) << endl;

    vector <int> v;
    v.push_back(10);
    v.push_back(12);
    v.push_back(16);
    v.push_back(20);
    v.push_back(22);

    cout << "Finding 16: " << binary_search(v.begin(),v.end(),16);
    sort(v.begin(),v.end());
    cout << endl;

    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *(i) << " ";
    }
    cout << endl;

    reverse(v.begin(),v.end());
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *(i) << " ";
    }
    cout << endl;


    return 0;
}