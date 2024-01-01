#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < key) {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] < key) {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    int A[] = {1,2,3,3,3,4,5,10};
    int n = sizeof(A) / sizeof(int);
    int key = 3;

    cout << "First occurrence of " << key << " is at index " << firstOcc(A,n,key) << endl;
    cout << "Last occurrence of " << key << " is at index " << lastOcc(A,n,key) << endl;
 
    return 0;
}