#include<iostream>
using namespace std;

int setBits(int n){
    int count = 0;
    while(n!=0){
        int bit = n&1;
        if(bit == 1){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int totalSetBits(int a, int b){
    a = setBits(a);
    b = setBits(b);

    return a + b;
}

int main(){
    int a = 2;
    int b = 3;
    int total = totalSetBits(a,b);
    cout << total << endl;

    return 0;
}