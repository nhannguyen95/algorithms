// Tested with https://practice.geeksforgeeks.org/problems/binary-array-sorting/0

#include <iostream>
#include <vector>
using namespace std;
	
void twoWayPartitioningFor(vector<int>& nums) {
	int lo = 0;
	for(int hi = 0; hi < nums.size(); hi++) {
		// nums[0..lo-1] = 0s
		// nums[lo..hi-1] = 1s
		// nums[hi..N] = unknown (not processed yet)
		if (nums[hi] == 0) swap(nums[lo++], nums[hi]);
	}
}

void twoWayPartitioningWhile(vector<int> & nums) {
	int lo = 0, hi = nums.size() - 1;
	while(lo <= hi) {
		// nums[0..lo-1] = 0s
		// nums[lo..hi] = unknown (not processed yet)
		// nums[hi+1..N] = 1s
		if (nums[lo] == 0) lo++;
		else swap(nums[lo], nums[hi--]);
		// Notice here that we don't increase `lo` when swap,
		// because after swapping, nums[lo] get new value and we
		// don't know if it is 0 or not.
	}
}

void printArray(const vector<int> nums) {
	for(int x : nums)
		cout << x << ' ';
	cout << '\n';
}

int main() {
	vector<int> nums({0,1,0,1,0,1});

	// Goal: 0s to the left, 1s to the right
	// Eg: 0 0 0 1 1 1

	// Toggle these 2
	// O(N) in time, O(1) in space
	twoWayPartitioningFor(nums);    // For style
	// twoWayPartitioningWhile(nums);  // While style

	printArray(nums);

	return 0;
}
