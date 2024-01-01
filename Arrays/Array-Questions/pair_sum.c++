#include<iostream>
using namespace std;

void pairSum(int arr[], int n, int s){
    for (int i = 0; i < n; i++)
    {
        for (int  j = i+1; j < n; j++)
        {
            if(arr[i] + arr[j] == s){
                cout << "[" << arr[i] << "," << arr[j] << "]" << endl;
            }
        }   
    }
}

int main(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A) / sizeof(int);
    int sum = 5;
    pairSum(A,n,sum);

    return 0;
}