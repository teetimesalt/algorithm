/**
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

Example 1:
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:
Input: nums = [1,2,3,4]
Output: 0

Example 3:
Input: nums = [1]
Output: 0

1 <= nums.length <= 104
-105 <= nums[i] <= 105
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      if (nums.size() < 2)
        return 0;
      vector<int> n(nums);

      sort(n.begin(), n.end());
      int start = -1, end = -1;

      for(int i = 0 ; i < nums.size() ; i++) {
        cout << "nums[i] : " << nums[i] << " n[i] : " << n[i] << " start: " << start << " end : " << end << endl;
        if (nums[i] != n[i]) {
          start = i;
          break;
        }
      }
      for(int i = nums.size()-1 ; i >= 0 ; i--) {
        cout << "nums[i] : " << nums[i] << " n[i] : " << n[i] << " start: " << start << " end : " << end << endl;
        if (nums[i] != n[i]) {
          end = i;
          break;
        }
      }
      cout << "start: " << start << " end : " << end << endl;

      if (start < end) {
        return end - start + 1;
      }
      return 0;
    }
};

int main() {
  Solution s;

  vector<int> e1 = {2, 6, 4, 8, 10, 9, 15};
  if (s.findUnsortedSubarray(e1) == 5) {
    cout << "Exam1 succeeded" << endl;
  } else {
    cout << "Exam1 failed" << endl;
  }
  return 0;
}