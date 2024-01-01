#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    char ch;
    cout << "Choose the operation you want to perform" << endl;
    cout << "'+' , '-' , '*' , '/' , '%'" << endl;
    cout << "Operation : ";
    cin >> ch;

    switch(ch){
        case '+':
            cout << a << "+" << b << " : " << a+b << endl;
            break;
        case '-':
            cout << a << "-" << b << " : " << a-b << endl;
            break;
        case '*':
            cout << a << "*" << b << " : " << a*b << endl;
            break;
        case '/':
            cout << a << "/" << b << " : " << a/b << endl;
            break;
        case '%':
            cout << a << "%" << b << " : " << a%b << endl;
            break;
        default:
            cout << "Invalid Operation" << endl;   
    }

    return 0;
}