#include<bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        } 
    }
}

void printMatrix(vector<vector<int>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }   
        cout << endl; 
    }
}

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    transpose(matrix);
    printMatrix(matrix);

    return 0;
}