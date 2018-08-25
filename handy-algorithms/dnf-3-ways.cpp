#include <iostream>
#include <vector>
using namespace std;

void threeWayPartitioningWhile(vector<int> & nums) {
	int lo = 0, mi = 0, hi = nums.size() - 1;
	while(mi <= hi) {
		// nums[0..lo-1] = 0s
		// nums[lo..mi-1] = 1s
		// nums[mi..hi] = unknown (not processed yet)
		// nums[hi+1..N] = 2s
		if (nums[mi] == 0) swap(nums[lo++], nums[mi++]);  // We increase `mi` because it already in correct position
		else if (nums[mi] == 1) mi++;
		else swap(nums[mi], nums[hi--]);
	}
}

void printArray(const vector<int> nums) {
	for(int x : nums)
		cout << x << ' ';
	cout << '\n';
}

int main() {
	vector<int> nums({2,0,1});

	// Goal: 0s to the left, 1s to middle, 2s to the right
	// Eg: 0 0 0 0 1 1 1 2 2 2 
  
  // O(N) in time, O(1) in space
	threeWayPartitioningWhile(nums);  // While style

	printArray(nums);

	return 0;
}
