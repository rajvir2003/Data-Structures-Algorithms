#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;

    node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

pair<int,int> findSmallestRange(vector<vector<int>> &KSortedArray, int k){
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node*, vector<node*>, compare> minHeap;
    // push first elements of K lists
    for(int i = 0; i < k; i++){
        int element = KSortedArray[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;
    while(!minHeap.empty()){
        node* temp = minHeap.top();
        minHeap.pop();
        int row = temp->row;
        int col = temp->col;

        mini = temp->data;
        // update answer if there a smaller range exists
        if(end-start > maxi-mini){
            start = mini;
            end = maxi;
        }
        // check if there is an element present in kth array
        if(col+1 < KSortedArray[row].size()){
            minHeap.push(new node(KSortedArray[row][col+1], row, col+1));
            maxi = max(maxi, KSortedArray[row][col+1]);
        }
        else{ // if no element is present in kth array then break the loop
            break;
        }
    }
    pair<int,int> ans;
    ans.first = start;
    ans.second = end;

    return ans;
}

int main(){
    vector<vector<int>> KSortedArray = {
        {1,3,5,7,9},
        {0,2,4,6,8},
        {2,3,5,7,11}
    };
    int k = KSortedArray.size();

    pair<int,int> ans = findSmallestRange(KSortedArray, k);
    cout << "Range : [" << ans.first << "," << ans.second << "]" << endl;

    return 0;
}