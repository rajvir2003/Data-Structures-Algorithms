#include<bits/stdc++.h>
using namespace std;

class SegTree {
    private:
    vector<int> seg;

    public:
    SegTree(int n) {
        seg.resize(n*4);
    }
    // TC: O(4*n) or ~ O(n)
    void build(int ind, int low, int high, int arr[]) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
    // TC: ~ O(log n)
    int query(int ind, int low, int high, int l, int r, int arr[]) {
        // no overlap
        if(r < low || l > high) return INT_MAX;
        // complete overlap
        if(low >= l && high <= r) return seg[ind];
        // partial overlap
        int mid = (low + high) >> 1;
        int left = query(2*ind+1, low, mid, l, r, arr);
        int right = query(2*ind+2, mid+1, high, l, r, arr);
        return min(left, right);
    }
    // TC: ~ O(log n)
    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if(i <= mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);

        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
};

int main(){
    int arr[] = {2, 4, 0, 5, 1, 9, 3, 10, 8};
    int n = sizeof(arr) / sizeof(int);
    vector<vector<int>> queries = {{0,4}, {5,7}, {3,5}};

    SegTree SGT(n);
    SGT.build(0, 0, n-1, arr);
    
    for(auto it: queries) {
        int l = it[0], r = it[1];
        cout << "Min Element between index " << l << " and " << r << ": ";
        cout << SGT.query(0, 0, n-1, l, r, arr) << endl;
    }

    return 0;
}