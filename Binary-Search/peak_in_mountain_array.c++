#include<iostream>
using namespace std;

int mountainPeak(int arr[], int size) {
    int start = 0;
    int end = size-1;

    while (start < end)
    {
        int mid = (start+end) / 2;

        if(arr[mid] < arr[mid+1]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return start;
}

int main(){
    int A[] = {0,1,3,5,6,8,7,4,2};
    int n = sizeof(A) / sizeof(int);

    cout << "Peak is at index " << mountainPeak(A,n) << endl;

    return 0;
}