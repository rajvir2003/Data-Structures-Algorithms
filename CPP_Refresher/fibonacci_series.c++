#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a = 0;
    int b = 1;

    cout << a << " ";
    cout << b << " ";

    for (int i = 1; i <= n; i++)
    {   
        int sum = a + b;
        cout << sum << " ";
        a = b;
        b = sum;
    }
    
    return 0;
}