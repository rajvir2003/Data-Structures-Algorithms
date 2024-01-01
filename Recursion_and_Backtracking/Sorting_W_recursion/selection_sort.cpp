#include<bits/stdc++.h>
using namespace std;

void sort(int* arr, int n){
    if(n == 0 || n == 1){
        return;
    }
    int mini = 0;
    for (int i = 0; i < n; i++)
    {   
        if(arr[i] < arr[mini]){
            mini = i;
        }
    }
    swap(arr[0], arr[mini]);

    sort(arr+1, n-1);
}

int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    
    return 0;
}