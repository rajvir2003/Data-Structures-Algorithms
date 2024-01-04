#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout << "Decimal number: ";
    cin >> n;
    float answer = 0;
    int i = 0;

    while(n != 0){

        int bit = n&1;  // checking the last bit
        answer = (bit * pow(10,i)) + answer;    
        i++;
        n = n >> 1;     // right shift to check the next bit
    }

    cout << "Binary number: " << answer << endl;

    return 0;
}