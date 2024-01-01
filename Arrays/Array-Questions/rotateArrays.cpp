#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotateArray(int arr[], int n, int degree) {
    int arr2[n] = {0};
    for (int i = 0; i < n; i++)
    {
        arr2[(i+degree)%n] = arr[i];
    }
    printArray(arr2,n);
}

int main(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A) / sizeof(int);
    int k = 2;

    rotateArray(A,n,k);

    return 0;
}