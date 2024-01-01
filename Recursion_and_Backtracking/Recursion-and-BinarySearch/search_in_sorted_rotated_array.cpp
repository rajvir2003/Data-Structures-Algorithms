#include<bits/stdc++.h>
using namespace std;

int binarySearch(int* arr, int start, int end, int target) {
    if(start > end){
        return -1;
    }
    int mid = start + (end-start) / 2;
    
    if(arr[mid] == target) {
        return mid;
    }
    else if(arr[mid] < target){
        return binarySearch(arr, mid+1, end, target);
    }
    else{
        return binarySearch(arr, start, mid-1, target);
    }
}

int getPivot(int* arr, int start, int end) {
    // base condition
    if(start == end) {
        return start;
    }

    int mid = start + (end-start) / 2;

    if(arr[mid] >= arr[0]){
        getPivot(arr, mid+1, end);
    }
    else{
        getPivot(arr, start, mid);
    }
}

int search(int* arr, int size, int target) {
    int pivot = getPivot(arr, 0, size-1);

    if(target >= arr[pivot] && target >= arr[0]){
        return binarySearch(arr, 0, pivot, target);
    }
    else{
        return binarySearch(arr, pivot, size-1, target);
    }
}

int main(){
    int arr[] = {3,4,5,6,7,8,8,1,2};
    int n = sizeof(arr) / sizeof(int);
    int key = 1;

    int ans = search(arr, n, key);
    cout << "Key is at index " << ans << endl;

    return 0;
}