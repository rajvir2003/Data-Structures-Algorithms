#include<bits/stdc++.h>
using namespace std;

// program to print count of prime numbers before 'n'
int countPrime(int n){
    vector<bool> prime(n+1,true);
    prime[0] = prime[1] = false;
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if(prime[i]){
            count++;

            for (int j = i*2; j < n; j = j+i)
            {
                prime[j] = false;
            }   
        }
    }
    return count;
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int count = countPrime(n);
    cout << "Total Prime Numbers before " << n << " is " << count << endl;

    return 0;
}