#include<bits/stdc++.h>
using namespace std;

bool binary_search(int* arr, int start, int end, int target) {
    int mid = (start + end) / 2;

    if(start > end) {   // means array is completely traversed and element is still not found
        return false;
    }

    if(arr[mid] == target){
        return true;
    }
    else if(arr[mid] < target) {
        return binary_search(arr, mid+1, end, target);
    }
    else{
        return binary_search(arr, start, mid-1, target);
    }
}

int main(){
    int arr[] = {10,12,15,19,23,27,34,45,50};
    int n = sizeof(arr) / sizeof(int);
    int key = 50;

    if(binary_search(arr, 0, n-1, key)){
        cout << "Key is present" << endl;
    }
    else{
        cout << "Key is not present" << endl;
    }

    return 0;
}