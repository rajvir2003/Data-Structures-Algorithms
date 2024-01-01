#include<bits/stdc++.h>
using namespace std;

void words(int digit) {
    vector<string> v = {"zero","one","two","three","four",
                       "five","six","seven","eight","nine"};
    cout << v[digit] << " ";
}

void sayDigits(int n) {
    // base condition
    if(n == 0) {
        return;
    }

    int digit = n % 10;
    n = n / 10;
    
    sayDigits(n);
    words(digit);
}

int main(){
    int n;
    cin >> n;

    sayDigits(n);

    return 0;
}