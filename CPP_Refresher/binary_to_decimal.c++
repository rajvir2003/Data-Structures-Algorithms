#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout << "Binary number: ";
    cin >> n;
    float answer = 0;
    int i = 0;

    while(n != 0){

        int digit = n % 10;    // to get the last digit
        if(digit == 1){
            answer = answer + pow(2,i);
        }
        i++;
        n = n / 10; 
    }

    cout << "Decimal number: " << answer << endl;

    return 0;
}