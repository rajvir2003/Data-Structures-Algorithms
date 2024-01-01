#include<bits/stdc++.h>
using namespace std;

int is_found(int* arr, int size, int target) {
    // base case/condition
    if(size == 0) {
        return false;
    }
    if(arr[0] == target){
        return true;
    }

    int remainingPart = is_found(arr+1, size-1, target);
    return remainingPart;
}

int main(){
    int arr[] = {23,65,34,78,26,100,95,50};
    int n = sizeof(arr) / sizeof(int);
    int key = 100;

    if(is_found(arr,n,key)){
        cout << "Key is present" << endl;
    }
    else{
        cout << "Key is not present" << endl;
    }

    return 0;
}