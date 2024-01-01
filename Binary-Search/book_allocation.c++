#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    if(m > n) {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        if(pageSum + arr[i] <= mid) {
            pageSum = pageSum + arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
                return false;
            }
            else{
                pageSum = 0;
                pageSum = pageSum + arr[i];
            }
        }
    }
    return true;
}

int bookAllocate(int arr[], int n, int m) {
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        end = end + arr[i];
    }
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if(isPossible(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans; 
}

int main(){
    int Books[] = {10,20,30,40};
    int n = sizeof(Books) / sizeof(int); // no. of books
    int m = 3; // no. of students

    int answer = bookAllocate(Books, n, m);
    cout << "Minimum of maximum no. of pages allocated are " << answer << endl;

    return 0;
}