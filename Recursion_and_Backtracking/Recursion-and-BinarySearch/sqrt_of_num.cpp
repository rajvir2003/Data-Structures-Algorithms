#include<bits/stdc++.h>
using namespace std;

int sqarert(int n, int start, int end) {
    // base condition
    if(start > end){
        return -1;
    }
    
    int mid = start + (end-start)/2;

    if(mid*mid == n){
        return mid;
    }
    else if(mid*mid < n){
        return sqarert(n, mid+1, end);
    }
    else{
        return sqarert(n, start, mid-1);
    }
}

int main(){
    int n;
    cin >> n;

    int ans = sqarert(n, 0, n-1);
    cout << ans << endl;

    return 0;
}