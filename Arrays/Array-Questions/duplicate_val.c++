#include<iostream>
using namespace std;

int duplicate(int arr[], int n){
    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = ans^arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        ans = ans^i;
    }
    return ans;
}

int main(){
    int A[] = {4 ,5, 8, 4, 6, 1, 2, 3, 7, 4};
    int n = sizeof(A) / sizeof(int);

    int dup = duplicate(A, n);
    cout << dup;
    return 0;
}