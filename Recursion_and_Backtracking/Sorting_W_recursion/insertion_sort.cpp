#include<bits/stdc++.h>
using namespace std;

void sort(int* arr, int n) {
    if(n == 0 || n == 1){
        return;
    }

    sort(arr, n-1);

    int last = arr[n-1];
    int j = n-2;

    while(j >= 0 && arr[j] > last){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;   
}

int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(int);

    sort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}