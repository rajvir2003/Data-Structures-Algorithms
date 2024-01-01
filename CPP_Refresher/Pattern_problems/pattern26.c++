#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int i = 1;
    while(i <= n){

        int j = 1;
        while(j <= n-i+1){
            cout << j;
            j = j + 1;
        }

        int star = 1;
        while(star <= i-1){
            cout << "*";
            star = star + 1;
        }

        star = star - 1;
        while(star!=0){
            cout << "*";
            star = star - 1;
        }

        j =  j - 1;
        while(j != 0){
            cout << j;
            j = j - 1;
        }

        cout << endl;
        i = i + 1;
    }
    return 0;
}