#include<bits/stdc++.h>
using namespace std;

void mergeSortedArrays(int arr1[], int arr2[], int m, int n, int arr3[]){
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    while(i < m && j < n) {

        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i < m) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while(j < n) {
        arr3[k] = arr2[j];
        j++;
        k++;
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
    int A[] = {1,3,4,5,7,9,10};
    int m = sizeof(A) / sizeof(int);
    int B[] = {2,5,6,8};
    int n = sizeof(B) / sizeof(int);
    int o = m+n;
    int C[o] = {0};

    mergeSortedArrays(A,B,m,n,C);
    printArray(C,o);

    return 0;
}