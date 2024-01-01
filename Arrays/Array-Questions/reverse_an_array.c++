#include<iostream>
using namespace std;

void traversal(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

void reverse(int arr[], int size){

    int i = 0;
    int j = size - 1;
    while(i <= j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    
}

int main(){
    int A[] = {45, 34, 56, 77, 24, 33, 100};
    int n = sizeof(A) / sizeof(int);

    cout << "Before Reverse: ";
    traversal(A, n);
    reverse(A, n);
    cout << "After Reverse: ";
    traversal(A, n);

    return 0;
}