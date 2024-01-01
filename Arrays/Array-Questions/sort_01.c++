#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[], int n){
    int i = 0;
    int j = n-1;

    while(i < j){
        while(arr[i] == 0){
            i++;
        }

        while(arr[j] == 1){
            j--;
        }

        if(arr[i] == 1 && arr[j] == 0){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

int main(){
    int A[] = {0,0,0,0,0,1,0,0,1,1,0,0,0,0};
    int n = sizeof(A) / sizeof(int);
    sort(A,n);
    printArray(A,n);

    return 0;
}