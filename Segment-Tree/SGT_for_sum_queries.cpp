#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

class SegTree {
private:
	vector<int> seg;

public:
	SegTree(int n) {
		seg.resize(n*4);
	}

	void build(int ind, int low, int high, int arr[]) {
		if(low == high) {
			seg[ind] = arr[low];
			return;
		}

		int mid = (low + high) >> 1;
		build(2*ind+1, low, mid, arr);
		build(2*ind+2, mid+1, high, arr);

		seg[ind] = seg[2*ind+1]  + seg[2*ind+2];
	}

	int query(int ind, int low, int high, int l, int r) {
		// non overlap
		if(l > high || r < low) return 0;
		// complete overlap
		if(low >= l && high <= r) return seg[ind];
		// partial overlap
		int mid = (low + high) >> 1;
		int left = query(2*ind+1, low, mid, l, r);
		int right = query(2*ind+2, mid+1, high, l, r);

		return left + right;
	}

	void update(int ind, int low, int high, int i, int val) {
		if(low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if(i <= mid) update(2*ind+1, low, mid, i, val);
		else update(2*ind+2, mid+1, high, i, val);

		seg[ind] = seg[2*ind+1] + seg[2*ind+2];
	}
};

void solve(int n, int m, int arr[], vector<vector<int>> &queries){
	SegTree SGT(n);
	SGT.build(0, 0, n-1, arr);

	for(auto &it: queries){
		int type = it[0];
		if(type == 1) {
			int l = it[1], r = it[2];
			cout << "Sum from index " << l << "-" << r << ": ";
			cout << SGT.query(0, 0, n-1, l, r) << endl;
		} else {
			int i = it[1], val = it[2];
			SGT.update(0, 0, n-1, i, val);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	vector<vector<int>> queries(m, vector<int>(3));
	// {type - 1, left, right}
	// {type - 2, index, value}
	for(int i = 0; i < m; i++){
		cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
	}
	solve(n, m, arr, queries);

	return 0;
}