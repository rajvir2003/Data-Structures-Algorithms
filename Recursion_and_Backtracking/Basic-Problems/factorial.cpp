#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    // base condition
    if(n == 0){
        return 1;
    }
    
    // recursive relation
    return n * fact(n-1);
}

int main(){
    int n;
    cin >> n;

    int factorial = fact(n);
    cout << "Factorial of " << n << " is " << factorial << endl;

    return 0;
}