#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target) {
    int low = 0, high = nums.size()-1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[low] <= nums[mid]) { // if left half is sorted
            if(target >= nums[low] && target < nums[mid]) {
                high = mid-1;  // if target lies b/w low - mid, then eleminate right half
            } else {
                low = mid+1;  // else eleminate left half
            }
        } else { // if right half is sorted
            if(target > nums[mid] && target <= nums[high]) {
                low = mid+1;  // if target lies b/w mid - high, then eleminate left half
            } else {
                high = mid-1;  // else eleminate right half
            }
        }
    }
    // return -1 if target not found
    return -1;
}

int main(){
    vector<int> nums = {7,8,9,1,2,3,4,5,6};
    int target = 8;
    int idx = search(nums, target);

    if(idx != -1) {
        cout << "Target found at index: " << idx << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}