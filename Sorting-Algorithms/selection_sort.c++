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
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}


int main(){
    int A[] {4,3,2,1};
    int n = 4;

    sort(A,n);
    printArray(A,n);
    return 0;
}