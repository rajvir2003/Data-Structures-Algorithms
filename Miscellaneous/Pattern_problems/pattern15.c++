#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;

    int i = 1;
    while(i <= n){

        int j = 1;
        while(j <= i){
            char c = 'A' + count;
            cout << c << " ";
            count = count + 1;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }

    return 0;
}