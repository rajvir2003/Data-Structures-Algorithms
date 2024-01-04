#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int counter  = 0;

    int i = 1;
    while(i <= n){

        int j = 1;
        while(j <= n){
            char c = 'A'+counter;
            cout << c;
            counter = counter + 1;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
    return 0;
}