#include<iostream>
using namespace std;

int BinarySearch(int arr[], int start, int end, int key) {

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int getPivot(int arr[], int n) {
    int start = 0;
    int end = n-1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return start;
}

int search(int arr[], int n, int key) {
    int pivot = getPivot(arr,n);

    if(arr[pivot] <= key && arr[n-1] >= key) {
        BinarySearch(arr,pivot,n-1,key);
    }
    else{
        BinarySearch(arr,0,pivot-1,key);
    }
}

int main(){
    int A[] = {6,8,9,12,15,20,24,0,1,3,4,5};
    int n = sizeof(A) / sizeof(int);
    int key = 1;

    int ans = search(A,n,key);
    cout << "Key is found at index " << ans << endl;

    return 0;
}