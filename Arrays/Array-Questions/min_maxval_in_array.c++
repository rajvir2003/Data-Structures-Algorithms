#include<iostream>
using namespace std;

int getMax(int arr[], int size){
    int maxVal = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        maxVal = max(maxVal,arr[i]);
        // if(maxVal < arr[i]){
        //     maxVal = arr[i];
        // }
    }
    return maxVal;  
}

int getMin(int arr[], int size){
    int minVal = INT32_MAX;
    for (int i = 0; i < size; i++)
    {
        if(minVal > arr[i]){
            minVal = arr[i];
        }
    }
    return minVal;
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;   
}

int main(){
    int A[] = {4,7,32,57,23,6,2};
    int n = 7;
    cout << "Elements of Array are ";
    printArray(A,n);
    int min = getMin(A,n);
    cout << "Minimum value in array is " << min << endl;
    int max = getMax(A,n);
    cout << "Maximum value in array is " << max << endl;

    return 0;
}