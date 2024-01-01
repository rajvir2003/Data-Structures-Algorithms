#include<iostream>
using namespace std;

bool search(int arr[], int n, int key){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == key){
            return 1;
        }
    }
    return 0;
}

int main(){
    int A[] = {54, 75, 23, 8, 2, 45, 100, 35};
    int n = sizeof(A)/sizeof(int);

    int key;
    cout << "Enter the element you want to search: ";
    cin >> key;

    int found = search(A, n, key);

    if( found ){
        cout << "Key is present" << endl;
    }
    else{
        cout << "Key is absent" << endl;
    }

    return 0;
}