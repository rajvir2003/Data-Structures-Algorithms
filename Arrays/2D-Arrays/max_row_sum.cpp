#include<bits/stdc++.h>
using namespace std;

int maxRowSum(int arr[3][3]) {
    int max = -1;
    int row;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        if(sum > max){
            max = sum;
            row = i;
        }    
    }
    cout << "Maximum sum is " << max << endl;
    return row;
}

int main(){
    int A[3][3] = {
        {6,9,2},
        {8,10,7},
        {5,3,4}
    };

    int ans = maxRowSum(A);
    cout << "MaxRowSum is at row " << ans << endl;

    return 0;
}