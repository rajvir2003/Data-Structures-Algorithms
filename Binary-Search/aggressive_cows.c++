#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid) {
    int cowCount = 1;
    int place = arr[0];

    for (int i = 0; i < n; i++)
    {
        if(arr[i] - place >= mid) {
            cowCount++;
            if(cowCount == k) {
                return true;
            }
            place = arr[i];
        }
    }
    return false;
}

int aggressive_cows(int arr[], int n, int k) {
    int start = 0;
    int end = -1;
    for (int i = 0; i < n; i++)
    {
        end = max(end,arr[i]);
    }
    int ans = -1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    
}

int main(){
    int stalls[] = {2,5,9,12}; 
    int n = sizeof(stalls) / sizeof(int);
    int k = 2; // no. of cows

    int answer = aggressive_cows(stalls, n, k);
    cout << "The maximum of minimum distance in which cows are placed is " << answer << endl;

    return 0;
}