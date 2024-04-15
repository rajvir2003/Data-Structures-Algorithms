#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {5, 7, 90, 12, 45, 2, 34};

    // to get maximum element from the vector
    int maxi = *max_element(v.begin(), v.end());
    cout << "Maximum element: " << maxi << endl;
    // to get minimum element from the vector
    int mini = *min_element(v.begin(), v.end());
    cout << "Minimum element: " << mini << endl;

    // to accumulate sum of elements in vector
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "sum of elements: " << sum << endl;

    // to reverse the vector
    reverse(v.begin(), v.end());
    for(auto it: v) cout << it << " ";
    cout << endl;

    // to sort the vector
    sort(v.begin(), v.end());
    for(auto it: v) cout << it << " ";
    cout << endl;

    // to check whether vector is sorted or not
    if(is_sorted(v.begin(), v.end())) {
        cout << "vector is sorted" << endl;
    } else {
        cout << "vector is unsorted" << endl;
    }

    // to check whether a substring is a part of string or not
    string str = "codeforces";
    string sub = "def";
    if(str.find(sub) == string::npos) {
        cout << sub << " is not a part of " << str << endl;
    } else {
        cout << sub << " is a part of " << str << endl; 
    }

    // find an element from the vector (linear search)
    // takes O(n)
    int x = 12;
    if(find(v.begin(), v.end(), x) != v.end()){
        cout << x << " is present" << endl;
    } else {
        cout << x << " is not present" << endl;
    }

    // find an element from the vector (binary search)
    // takes O(log n)
    if(binary_search(v.begin(), v.end(), x)){
        cout << x << " is present" << endl;
    } else {
        cout << x << " is not present" << endl;
    }

    // to count number of set bits(1) in a number
    int num = 7;
    int setBits = __builtin_popcount(num); // for integer
    long long num2 = 3284273234932435;
    int result = __builtin_popcountll(num2);
    cout << "setBits in " << num << ": " << setBits << endl;
    cout << "setBits in " << num2 << ": " << result << endl;

    return 0;
}