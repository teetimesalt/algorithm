/**
https://leetcode.com/problems/count-of-range-sum/

Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

Example 1:
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.

Example 2:
Input: nums = [0], lower = 0, upper = 0
Output: 1
*/
#include <iostream>
#include <string>
#include <vector>

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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
      int ans = 0;
      int s = 0, e = 0;
      bool finished = false;
      int sum = nums[s];
      while(!finished) {
        print("nums[e] ", nums[e]);
        sum += nums[e];
        print("sum:", sum);
        print("e:", e);
        if (lower <= sum && sum <= upper) {
          ans++;
          print("ans:", ans);
          while(s < e) {
            sum -= nums[s++];
            sum += nums[s];
            print("sum:", sum);
            print("s:", s);
            if (lower <= sum && sum <= upper)
              ans++;
          }
        }
        sum -= nums[e];
        print("moving e sum:", sum);
        e++;
        if (e >= nums.size())
          finished = true;
      } 
      return ans;
    }
};

int main() {
  vector<int> exam1 = {-2,5,-1};
  Solution s;
  print("exam1:", s.countRangeSum(exam1, -2, 2));
  return 0;
}