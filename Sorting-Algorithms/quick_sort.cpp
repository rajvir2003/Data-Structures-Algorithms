#include<bits/stdc++.h>
using namespace std;

int partition(int* arr, int low, int high) {
    int Pivot = low;

    int i = low;
    int j = high;
    while (i < j)
    {
        while(arr[i] <= arr[Pivot] && i <= high){
            i++;
        }
        while(arr[j] > arr[Pivot] && j >= low){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void quickSort(int* arr, int low, int high) {
    if(low < high) {
        int PivotIndex = partition(arr, low, high);

        quickSort(arr, low, PivotIndex-1);
        quickSort(arr, PivotIndex+1, high);
    }
}

int main(){
    int arr[] = {9, 9, 9, 8, 2, 3, -6 };
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}