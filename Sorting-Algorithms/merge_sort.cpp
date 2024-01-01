#include<bits/stdc++.h>
using namespace std;

void merge(int* A, int low, int high){
    int mid = (low + high) / 2;
    int* B = new int[high+1];

    int i = low;
    int j = mid+1;
    int k = low;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++; k++;
        }
        else{
            B[k] = A[j];
            j++; k++;
        }
    }

    while(i <= mid){
        B[k] = A[i];
        i++; k++;
    }
    while(j <= high){
        B[k] = A[j];
        j++; k++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    delete []B;
}

void MergeSort(int* arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        merge(arr, low, high);
    }
}

int main(){
    int arr[] = {34,56,28,14,35,9,10};
    int n = sizeof(arr)/sizeof(int);

    MergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}