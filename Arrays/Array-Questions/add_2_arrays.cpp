#include<bits/stdc++.h>
using namespace std;

vector<int> Sum_of_2_Arrays(int a[], int b[], int n, int m) {
    int i = n-1;
    int j = m-1;
    int carry = 0;
    vector<int> ans;

    while(i >= 0 && j >= 0) {
        int sum = a[i] + b[j] + carry;
        int val = sum % 10;
        carry = sum / 10;
        ans.push_back(val);
        i--; j--;
    }

    while(i >= 0) {
        int sum = a[i] + carry;
        int val = sum % 10;
        int carry = sum / 10;
        ans.push_back(val);
        i--;
    }

    while(j >= 0) {
        int sum = b[j] + carry;
        int val = sum % 10;
        int carry = sum / 10;
        ans.push_back(val);
        j--;
    }

    while(carry != 0) {
        int sum = carry;
        int val = sum % 10;
        carry = sum / 10;
        ans.push_back(val);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    int arr1[] = {9,7,6,5};
    int arr2[] = {2,4,9};
    int n = sizeof(arr1) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);

    vector <int> v = Sum_of_2_Arrays(arr1, arr2, n, m);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it);
    }
    cout << endl;

    return 0;
}