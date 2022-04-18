/**
https://leetcode.com/problems/binary-search/

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

#define DEBUG

void print(string&& msg, vector<int> point) {
#ifdef DEBUG
  cout << msg << " ";
  vector<int>::iterator it;

  for(it = point.begin() ; it != point.end() ; it++) {
    cout << *it << " ";
  }
  cout << endl;
#endif
}

void print(string &&msg, vector<vector<int>> &points) {
#ifdef DEBUG
  cout << msg << " ";
  vector<vector<int>>::iterator it;

  for(it = points.begin() ; it != points.end() ; it++) {
    print("", *it);
  }
  cout << endl;
#endif
}

void print(string &&msg, int value) {
#ifdef DEBUG
  cout << msg << " " << value << endl;
#endif
}
class Solution {
public:
    int search(vector<int>& nums, int target) {
      if (nums.size() == 0)
        return -1;
      if (nums.size() == 1) {
        if (nums[0] == target)
          return 0;
        return -1;
      }
      int begin = 0;
      int end = nums.size()+1;
      int mid = (end-begin)/2;
      print("begin:", begin);
      print("end :", end);
      print("mid:", mid);

      while(nums[mid] != target) {
        if (nums[mid] < target) {
          begin = mid + 1;
        } else {
          end = mid;
        }
        mid = begin + (end-begin)/2;
        print("begin:", begin);
        print("end :", end);
        print("mid:", mid);

        if (begin == end)
          return -1;
      }
      return mid;
    }
};

int main() {
  vector<int> exam1 = {-1,0,3,5,9,12};
  print("exam1", exam1);
  Solution s;
  s.search(exam1, 9);
  s.search(exam1, 2);
  return 0;
}