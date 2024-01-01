#include<bits/stdc++.h>
using namespace std;

int getPivot(int* arr, int start, int end) {
    // base condition
    if(start == end) {
        return arr[start];
    }

    int mid = start + (end-start) / 2;

    if(arr[mid] >= arr[0]){
        getPivot(arr, mid+1, end);
    }
    else{
        getPivot(arr, start, mid);
    }
}

int main(){
    int arr[] = {3,4,5,6,1,2};
    int n = sizeof(arr) / sizeof(int);

    int pivot = getPivot(arr, 0, n-1);
    cout << pivot << endl;

    return 0; 
}