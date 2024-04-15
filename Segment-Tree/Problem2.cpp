#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

// Codeforces Div. 1 C) problem - Sereja and Brackets

struct info {
	int open, close, full;

	info() {
		open = 0; close = 0; full = 0;
	}

	info(int _open, int _close, int _full){
		open = _open;
		close = _close;
		full = _full;
	}
};

class SegTree {
    public:
    vector<info> seg;

    SegTree(int n) {
        seg.resize(n*4);
    }

    info merge(info left, info right) {
    	int _open = left.open + right.open - min(left.open, right.close);
    	int _close = left.close + right.close - min(left.open, right.close);
    	int _full = left.full + right.full + min(left.open, right.close);
    	return info(_open, _close, _full);
    }

    void build(int ind, int low, int high, string &s) {
        if(low == high) {
        	seg[ind] = info(s[low]=='(', s[low]==')', 0);
  			return;
        }

        int mid = (low + high) >> 1;
        build(2*ind+1, low, mid, s);
        build(2*ind+2, mid+1, high, s);

        seg[ind] = merge(seg[2*ind+1], seg[2*ind+2]);
    }

    info query(int ind, int low, int high, int l, int r) {
    	if(low > r || high < l) return info();
    	if(low >= l && high <= r) return seg[ind];

    	int mid = (low + high) >> 1;
    	info left = query(2*ind+1, low, mid, l, r);
    	info right = query(2*ind+2, mid+1, high, l, r);

    	return merge(left, right);
    }
};

void solve(string &s, vector<vector<int>> &queries){
	int n = s.length();
	SegTree SGT(n);
	SGT.build(0, 0, n-1, s);

	for(auto &it: queries){
		int l = it[0]-1, r = it[1]-1;
		info ans = SGT.query(0, 0, n-1, l, r);
		cout << ans.full * 2 << endl;
	}
}

int main(){
	string s;
	cin >> s;
	int m;
	cin >> m;
	vector<vector<int>> queries(m, vector<int>(2));
	for(int i = 0; i < m; i++){
		cin >> queries[i][0] >> queries[i][1];
	}
	solve(s, queries);

	return 0;
}