/**
https://leetcode.com/problems/wiggle-subsequence/

A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.


Example 1:
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).

Example 2:
Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).

Example 3:
Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
      int index = 0, count = 0;
      typedef enum WIG {
        NONE,
        POS,
        NEG
      } WIG;
      WIG w = NONE;
      while(index+1 < nums.size()) {
        WIG w_ = NONE;
        if (nums[index+1]-nums[index] > 0) { //같을 경우? 
          w_ = POS;
        } else if (nums[index+1]-nums[index] == 0) {
          index++; continue;
        } else {
          w_ = NEG;
        }

        if (w != w_) {
          count++;
          w = w_;
        }
        index++;
      }
      return count+1;
    }
};

int main() {
  Solution s;

  vector<int> e1 = {1,7,4,9,2,5};
  if (s.wiggleMaxLength(e1) == 6) {
    cout << "Exam1 succeeded" << endl;
  } else {
    cout << "Exam1 failed" << endl;
  }

  vector<int> e2 = {1,17,5,10,13,15,10,5,16,8};
  if (s.wiggleMaxLength(e2) == 7) {
    cout << "Exam2 succeeded" << endl;
  } else {
    cout << "Exam2 failed" << endl;
  }

  vector<int> e3 = {1,2,3,4,5,6,7,8,9};
  if (s.wiggleMaxLength(e3) == 2) {
    cout << "Exam3 succeeded" << endl;
  } else {
    cout << "Exam3 failed" << endl;
  }

  vector<int> e4 = {0, 0};
  if (s.wiggleMaxLength(e4) == 1) {
    cout << "Exam4 succeeded" << endl;
  } else {
    cout << "Exam4 failed" << endl;
  }
}