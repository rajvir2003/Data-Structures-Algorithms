#include<bits/stdc++.h>
using namespace std;

int get_sum(int* arr, int size) {
    // base condition
    if(size == 0) {
        return 0;
    }
    if(size == 1) {
        return arr[0];
    }

    // recursive relation
    int sum = arr[0] + get_sum(arr+1, size-1);
    return sum;
}

int main(){
    int arr[] = {2,8,2,1,5,7};
    int n = sizeof(arr) / sizeof(int);

    int sum = get_sum(arr,n);
    cout << "Sum of array is " << sum << endl;

    return 0;
}