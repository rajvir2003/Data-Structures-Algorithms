#include<bits/stdc++.h>
using namespace std;

void row_wise_sum(int arr[3][3]){
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << endl;
    } 
}

void col_wise_sum(int arr[3][3]){
    for (int col = 0; col < 3; col++)
    {
        int sum = 0;
        for (int row = 0; row < 3; row++)
        {
            sum = sum + arr[row][col];
        }
        cout << sum << endl;
    } 
}

int main(){
    int arr[3][3] = {
        {23,43,64},
        {74,13,95},
        {45,37,83}
    };

    row_wise_sum(arr);
    cout << endl;
    col_wise_sum(arr);

    return 0;
}