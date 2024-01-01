#include<iostream>
using namespace std;

int sumOfElements(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    int sum = sumOfElements(arr,n);
    cout << "Sum of all elements in the array is " << sum << endl;
    
    return 0;
}