#include<bits/stdc++.h>
using namespace std;

bool isPresent(int arr[3][3], int key){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j] == key){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[3][3] = {
        {12,10,8},
        {5,9,2},
        {7,6,15}
    };
    int key;
    cout << "Enter the element you want to search: ";
    cin >> key;

    if(isPresent(arr,key)){
        cout << "Element found" << endl;
    }
    else{
        cout << "Element not found" << endl;
    }

    return 0;
}