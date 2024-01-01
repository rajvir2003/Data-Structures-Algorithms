#include<iostream>
using namespace std;

void intersection(int arr1[], int arr2[], int n, int m){
    int i = 0;
    int j = 0;
    
    while (i < n && j < m)
    {
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}

int main(){
    int A[] = {2,2,3,4,5,5,5,7,8};
    int n = 9;
    int B[] = {2,2,4,5,7};
    int m = 5;

    intersection(A,B,n,m);

    return 0;
}