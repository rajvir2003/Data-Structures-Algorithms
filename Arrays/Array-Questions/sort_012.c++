// Also known as dutch national flag problem (three pointer approach)
#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[], int n) {
    int low = 0;
    int mid = 0;
    int high = n-1;

    while (mid <= high)
    {
        if(arr[mid] == 0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main(){
    int A[] = {1,0,2,1,2,0,0,1};
    int n = sizeof(A) / sizeof(int);

    sort(A,n);
    printArray(A,n);

    return 0;
}