#include<bits/stdc++.h>
using namespace std;

void move(int arr[], int n) {
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        if(arr[j] != 0) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;  
}

int main(){
    int arr[] = {2,1,0,0,0,5};
    int n = sizeof(arr) / sizeof(int);
    move(arr,n);
    print(arr,n);

    return 0;
}