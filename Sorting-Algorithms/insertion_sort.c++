#include<iostream>
using namespace std;

void sort(int arr[], int n) {
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while (j >= 0)
        {
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            j--;
        }
        
        arr[j+1] = temp;
        
    }
    
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int A[] = {50,40,30,20,10};
    int n = sizeof(A) / sizeof(int);
    sort(A,n);
    printArray(A,n);

    return 0;
}