/* Maximum Subarray problem
https://leetcode.com/problems/maximum-subarray/description/#

Note: all solution below return the largest (negative) element
if there's no positive one in the array.

Divide and conquer Solution:
  - Time complexity:
    - T(N) = 2T(N/2) + Θ(N) => O(NlogN)

  - Space complexity:
    - The recursion depth is logN, each recursive call is O(1),
      so O(logN) is space.

Kadane's Solution:
  - Time complexity: O(N)
  - Space complexity: O(1)
  - Hard to keep track of indices of the result.

Linear Solution (this solution is easier to keep track of indices
of the maximum subarray):
  - Time complexity: O(N)
  - Space complexity: O(1)

*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Result {
  int low, high, sum;
  Result(int low, int high, int sum)
    : low(low), high(high), sum(sum) {}
};

// ----------DIVIDE AND CONQUER------------

Result maxCrossingSubArray_dac(
  const vector<int> & A, int low, int mid, int high) {
  int leftSum = INT_MIN;
  int leftId = mid;
  int sum = 0;
  for(int i = mid; i >= low; i--) {
    sum += A[i];
    if (sum > leftSum) {
      leftSum = sum;
      leftId = i;
    }
  }

  int rightSum = INT_MIN;
  int rightId = mid + 1;
  sum = 0;
  for(int i = mid+1; i <= high; i++) {
    sum += A[i];
    if (sum > rightSum) {
      rightSum = sum;
      rightId = i;
    }
  }

  return Result(leftId, rightId, leftSum + rightSum);
}

Result maxSubArray_dac(
  const vector<int> & A, int low, int high) {
  // Base case
  if (low == high) return Result(low, high, A[low]);

  int mid = low + (high - low) / 2;
  Result left = maxSubArray_dac(A, low, mid);
  Result right = maxSubArray_dac(A, mid+1, high);
  Result cross = maxCrossingSubArray_dac(A, low, mid, high);

  if (left.sum >= right.sum && left.sum >= cross.sum)
    return left;
  if (right.sum >= left.sum && right.sum >= cross.sum)
    return right;
  return cross;
}

Result maxSubArray_dac(const vector<int> & A) {
  return maxSubArray_dac(A, 0, A.size() - 1);
}

// ---------------KADANE'S-----------------

void maxSubArray_kadane(const vector<int> & A) {
  int maxEndingHere = A[0], maxSoFar = A[0];
  for(int i = 1; i < A.size(); i++) {
      maxEndingHere = max(maxEndingHere + A[i], A[i]);
      maxSoFar = max(maxSoFar, maxEndingHere);
  }
  return maxSoFar;
}

// -----------------LINEAR-----------------

Result maxSubArray_linear(const vector<int> & A) {
  int res = INT_MIN, sum = 0;
  int left = 0, right = 0, runningLeft = 0;
  for(int i = 0; i < A.size(); i++) {
    sum += A[i];
    if (sum > res) {
      res = sum;
      left = runningLeft;
      right = i;
    }
    if (sum < 0) {
      sum = 0;
      runningLeft = i + 1;
    }
  }
  return Result(left, right, res);
}
