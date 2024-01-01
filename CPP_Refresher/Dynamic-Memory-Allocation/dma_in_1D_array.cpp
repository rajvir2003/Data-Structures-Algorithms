#include<bits/stdc++.h>
using namespace std;

int main(){
    char* ch = new char;
    delete ch;

    int* arr = new int[5]; // creating a dynamic array
    for (int i = 0; i < 5; i++)
    {
        // *(arr+i) = arr[i]
        arr[i] = 2;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    delete []arr;  // deallocates the memory assigned to dynamic array
    

    return 0;
}