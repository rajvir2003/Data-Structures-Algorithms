#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int index, int size){
    int largest = index;
    int left = (index*2)+1;
    int right = (index*2)+2;

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != index){
        swap(arr[index], arr[largest]);
        heapify(arr, largest, size);
    }
}

vector<int> mergeTwoBinaryMaxHeaps(vector<int> &a, vector<int> &b){
    vector<int> arr;
    for(auto i: a){
        arr.push_back(i);
    }
    for(auto i: b){
        arr.push_back(i);
    }

    int n = arr.size();
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr, i, n);
    }
    return arr;
}

int main(){
    vector<int> a = {10, 15, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> ans = mergeTwoBinaryMaxHeaps(a, b);
    for(auto i : ans){
        cout << i << " ";
    } cout << endl;

    return 0;
}