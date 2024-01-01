#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> matrix, int target){
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = (row*col) - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        int element = matrix[mid/col][mid%col];

        if(element == target){
            return true;
        }
        else if(element < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> v = {
        {2,4,6,8},
        {9,11,13,15},
        {16,18,20,25}
    };
    int target;
    cout << "Enter the element you want to search: ";
    cin >> target;

    if(search(v, target)){
        cout << "Element is present" << endl;
    }
    else{
        cout << "Element is not present" << endl;
    }

    return 0;
}