#include<bits/stdc++.h>
using namespace std;

// Kadane's Algorithm to find maximum subarray sum
int maxSubarraySum(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    return maxi;
}

void printMaxSumSubarray(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int start, ansStart, ansEnd;  // will track subarray start and end
    start = ansStart = ansEnd = -1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(sum == 0) start = i;
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start; ansEnd = i;
        }
        if(sum < 0) sum = 0;
    }

    cout << "[ ";
    for(int i = ansStart; i <= ansEnd; i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main(){
    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};
    int n = arr.size();
    int ans = maxSubarraySum(arr, n);
    cout << "Maximum sub-array sum: " << ans << endl;
    cout << "Maximum sum subArray: ";
    printMaxSumSubarray(arr, n);

    return 0;
}