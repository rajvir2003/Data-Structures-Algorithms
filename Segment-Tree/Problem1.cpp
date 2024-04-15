#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

// Codeforces Div. 2 D) problem - Xenia and Bit Operations

class SegTree {
    public:
    vector<int> seg;

    SegTree(int n) {
        seg.resize(n*4);
    }

    void build(int ind, int low, int high, int arr[], int OR) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(2*ind+1, low, mid, arr, !OR);
        build(2*ind+2, mid+1, high, arr, !OR);

        if(OR) seg[ind] = seg[2*ind+1] | seg[2*ind+2];
        else seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }
   
    void update(int ind, int low, int high, int i, int val, int OR) {
        if(low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if(i <= mid) update(2*ind+1, low, mid, i, val, !OR);
        else update(2*ind+2, mid+1, high, i, val, !OR);

        if(OR) seg[ind] = seg[2*ind+1] | seg[2*ind+2];
        else seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }
};

void solve(int n, int m, int arr[], vector<vector<int>> &queries){
	int sz = pow(2, n);
	SegTree SGT(sz);

	if(n % 2 == 0) SGT.build(0, 0, sz-1, arr, 0);
	else SGT.build(0, 0, sz-1, arr, 1);

	for(auto &it: queries){
		int i = it[0]-1, val = it[1];
		if(n % 2 == 0) SGT.update(0, 0, sz-1, i, val, 0);
		else SGT.update(0, 0, sz-1, i, val, 1);
		cout << SGT.seg[0] << endl;
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	int sz = pow(2, n);
	int arr[sz];
	for(int i = 0; i < sz; i++){
		cin >> arr[i];
	}
	vector<vector<int>> queries(m, vector<int> (2));
	for(int i = 0; i < m; i++){
		cin >> queries[i][0] >> queries[i][1];
	}
	solve(n, m, arr, queries);

	return 0;
}