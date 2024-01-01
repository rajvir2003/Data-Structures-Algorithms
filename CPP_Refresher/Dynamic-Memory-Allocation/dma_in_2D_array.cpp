#include<bits/stdc++.h>
using namespace std;

int main(){
    int row;
    cin >> row;
    int col;
    cin >> col;

    // creating a 2-D array
    int** arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    // taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // deallocating memory from 2-D array
    for (int i = 0; i < row; i++)
    {
        delete [] arr[i];
    }

    delete []arr;
    
    return 0;
}