#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{return;}
        }
    }

    void Delete(){
        if(size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size){
            int left = 2*i;
            int right = (2*i)+1;

            if(left <= size && arr[left] > arr[i]){
                if(right <= size && arr[right] > arr[left]){
                    swap(arr[i], arr[right]);
                    i = right;
                }
                else{
                    swap(arr[i], arr[left]);
                    i = left;
                }
            }
            else if(right <= size && arr[right] > arr[i]){
                swap(arr[i], arr[right]);
                i = right;
            }
            else{return;}
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        } cout << endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2;
    int right = i*2+1;

    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n){
    int size = n;

    while(size > 1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main(){
    heap h;
    h.insert(56);
    h.insert(52);
    h.insert(54);
    h.insert(50);
    h.insert(49);
    h.insert(53);
    h.print();
    // cout << "INSERT 55: ";
    // h.insert(55);
    // h.print();
    // cout << "INSERT 70: ";
    // h.insert(70);
    // h.print();

    h.Delete();
    h.print();
    cout << endl << endl;

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = (sizeof(arr)/sizeof(int))-1;
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }

    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    heapSort(arr, n);
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}