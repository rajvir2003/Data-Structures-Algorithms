#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

// count inversion pairs i.e where i < j and arr[i] > arr[j]

class SegTree{
private:
    vector<int> seg;
public:
    SegTree(int n){
        seg.resize(4*n);
    }
    
    void build(int ind, int low, int high, vector<int> &arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    
    int query(int ind, int low, int high, int l, int r){
        if(l > high || r < low) return 0;
        if(low >= l && high <= r) return seg[ind];
        int mid = (low + high) >> 1;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return left + right;
    }
    
    void update(int ind, int low, int high, int i, int val){
        if(low == high){
            seg[ind] += val;
            return;
        }
        int mid = (low + high) >> 1;
        if(i <= mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
};

void solve(int n, vector<int> &arr){
	int maxi = *max_element(arr.begin(),arr.end());

    vector<int> freq(maxi+1,0);
    for(auto &it: arr) freq[it]++;
    
    int sz = maxi+1;
    SegTree SGT(sz);
    SGT.build(0, 0, sz-1, freq);
    
    int count = 0;
    for(int i = 0; i < n; i++){
        SGT.update(0, 0, sz-1, arr[i], -1);
        count += SGT.query(0, 0, sz-1, 0, arr[i]-1);
    }
    cout << count << endl;
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	solve(n, arr);

	return 0;
}