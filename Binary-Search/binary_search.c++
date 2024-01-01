#include<iostream>
using namespace std;

int search(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;
    
    while (start <= end ) 
    {
        // int mid = (start + end) / 2;
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

int main(){
    int A[] = {2,5,8,12,18,23,25,30};
    int n = sizeof(A) / sizeof(int);
    int key = 30;

    int index = search(A,n,key);
    cout << "Index of " << key << " is " << index << endl;
    return 0;
}