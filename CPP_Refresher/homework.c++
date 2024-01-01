#include<iostream>
using namespace std;

int main(){
    int amount;
    cin >> amount;
    int Rs100, Rs50, Rs20, Rs1;
    int x = 1;

    switch(x){
        case 1:
            Rs100 = amount / 100;
            amount = amount % 100;
            cout << "100 * " << Rs100 << endl;

        case 2:
            Rs50 = amount / 50;
            amount = amount % 50;
            cout << "50 * " << Rs50 << endl;

        case 3:
            Rs20 = amount / 20;
            amount = amount % 20;
            cout << "20 * " << Rs20 << endl;

        case 4:
            Rs1 = amount / 1;
            cout << "1 * " << Rs1 << endl;
            break;
    }

    return 0;
}