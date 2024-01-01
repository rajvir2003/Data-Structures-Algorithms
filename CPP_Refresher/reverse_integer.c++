#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int answer = 0;
    int i = 0;

    while(n != 0){
        int digit = n % 10;

        answer = (answer * 10) + digit;
        i++;

        n = n / 10;
    }

    cout << answer << endl;
    return 0;
}