#include<iostream>
using namespace std;

double getSqrt(int n) {
    int start = 0;
    int end = n;
    double ans = -1;

    while(start <= end) {
        double mid = start + (end - start) / 2;

        if(mid * mid == n){
            return mid;
        }
        else if(mid*mid < n) {
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    double sqrt = getSqrt(n);
    cout << sqrt << endl;

    return 0;
}