#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	pbds A; // declaration

	// inserting elements
	A.insert(1);
	A.insert(10);
	A.insert(2);
	A.insert(7);

	cout << "A = ";
	for(auto &it: A){
		cout << it << " ";
	} cout << endl << endl;

	// finding kth element
	cout << "0th element: " << *A.find_by_order(0) << endl;
	cout << "1st element: " << *A.find_by_order(1) << endl;
	cout << "2nd element: " << *A.find_by_order(2) << endl;
	cout << "3rd element: " << *A.find_by_order(3) << endl;
	cout << endl;

	// finding number of elements smaller than X
	cout << "No. of elems lesser than 6: " << A.order_of_key(6) << endl;
	cout << "No. of elems lesser than 8: " << A.order_of_key(8) << endl;
	cout << "No. of elems lesser than 2: " << A.order_of_key(2) << endl;
	cout << "No. of elems lesser than 1: " << A.order_of_key(1) << endl;
	cout << endl;

	// lower bound -> lower bound of X = first element >= X in the set
	cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
	cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
	cout << endl;

	// upper bound -> upper bound of X = first element > X in the set
	cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
    cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
    cout << endl;

    // Remove elements
    A.erase(7);

    cout << "A = ";
	for(auto &it: A){
		cout << it << " ";
	} cout << endl << endl;

	return 0;
}