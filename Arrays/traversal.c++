#include<iostream>
using namespace std;

void traversal(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

int main(){
    int A[] = {34, 2, 66, 23, 54, 7};
    int n = sizeof(A)/sizeof(int);

    traversal(A,n);
    
    return 0;
}