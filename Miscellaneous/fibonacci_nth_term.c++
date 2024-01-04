#include<iostream>
using namespace std;

int fib_nth_term(int n){
    
    int a = 0;
    int b = 1;
    int arr[100];

    arr[0] = 0;
    arr[1] = a;
    arr[2] = b;

    for (int i = 3; i < 10; i++)
    {
        int next = a+b;
        a = b;
        b = next;
        arr[i] = next;
    }
    
    return arr[n];
}

int main(){
    int n;
    cin >> n;

    int nth_term = fib_nth_term(n);
    cout << nth_term << endl;

    return 0;
}