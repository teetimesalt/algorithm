/**
https://leetcode.com/problems/maximum-gap/

Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

Example 1:

Input: nums = [3,6,9,1]
Output: 3


Example 2:
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

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
    int max(int a, int b) {
      return a > b ? a : b;
    }

    int maximumGap(vector<int>& nums) {
      if (nums.size() < 2)
        return 0;
      int result = 0;
      sort(nums.begin(), nums.end());
      print("sorted nums:", nums);

      for (int i = 1 ; i < nums.size() ; i++) {
        result = max(result, nums[i]-nums[i-1]);
      }
      return result;
    }
};

int main() {
  Solution s;
  vector<int> exam1 = {3, 6, 9, 1};
  print("exam1 ", s.maximumGap(exam1));

  vector<int> exam2 = {10};
  print("exam2 ", s.maximumGap(exam2));
  return 0;
}