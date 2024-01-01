#include<bits/stdc++.h>
using namespace std;

bool is_sorted(int* arr, int size) {
    // base condition
    if(size == 0 || size == 1) {
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    
    // recursive relation
    bool remainingPart = is_sorted(arr+1, size-1);
    return remainingPart;
}

int main(){
    int arr[] = {1,3,4,6,7,8,9};
    int n = sizeof(arr) / sizeof(int);

    if(is_sorted(arr,n)){
        cout << "Array is Sorted" << endl;
    }
    else{
        cout << "Array is not Sorted" << endl;
    }
    
    return 0;
}