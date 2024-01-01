// pivot -> minimum value in array
// Finding pivot using binary search
#include<iostream>
using namespace std;

int getPivot(int arr[],int n) {
    int start = 0;
    int end = n-1;

    while (start < end)
    {
        int mid = (start + end) / 2;
        
        if(arr[mid] >= arr[0]){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    return start;
}

int main(){
    int A[] = {5,7,10,12,2,3,4};
    int n = sizeof(A) / sizeof(int);

    int pivot = getPivot(A,n);
    cout << "Pivot is at index " << pivot << endl;

    return 0;
}