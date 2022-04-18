/**
https://leetcode.com/problems/jump-game/

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define DEBUG

template <typename T>
void print(string &&msg, T&& value) {
#ifdef DEBUG
  cout << msg << " " << value << endl;
#endif
}

template <typename T>
void print(string &&msg, vector<T> &vec) {
#ifdef DEBUG
  cout << msg << " ";
  typename vector<T>::iterator it;

  for(it = vec.begin() ; it != vec.end() ; it++) {
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

class Solution {
public:
    bool canJump(vector<int>& nums) {
      if (nums.size() == 1)
        return true;

      int index = 0;
      while(nums[index] != 0) {
        print("index ", index);
        print("nums[index] ", nums[index]);
        if (nums.size() <= index || nums.size() - 1 <= index + nums[index]) {
          return true;
        }
        if (nums[index] == 1) {
          print("continue nums[i] ", nums[index]);
          index++;
          continue;
        }
        int max_distance = -1;
        int max_index = -1;
        for(int i = index + 1 ; i <= index + nums[index] ; i++) {
          if (max_distance < i + nums[i]) {
            max_distance = i + nums[i];
            max_index = i;
          }
        }
        if (max_index > 0) {
          index = max_index;
        } else {
          return false;
        }
      }
      return false;
    }
};

int main() {
  Solution s;
  vector<int> ans1 = {2,3,1,1,4};
  if (s.canJump(ans1)) {
    cout << ">>>>> ans1  Succeeded" << endl;
  } else {
    cout << ">>>>> ans1  Failed" << endl;
  }

  vector<int> ans2 = {3,2,1,0,4};
  if (!s.canJump(ans2)) {
    cout << ">>>>> ans2 Succeeded" << endl;
  } else {
    cout << ">>>>> ans2 Failed" << endl;
  }

  vector<int> ans3 = {2, 0};
  if (s.canJump(ans3)) {
    cout << ">>>>> ans3  Succeeded" << endl;
  } else {
    cout << ">>>>> ans3  Failed" << endl;
  }

  vector<int> ans4 = {1,1,2,2,0,1,1};
  if (s.canJump(ans4)) {
    cout << ">>>>> ans4  Succeeded " << endl;
  } else {
    cout << ">>>>> ans4  Failed" << endl;
  }

  vector<int> ans6 = {5,9,3,2,1,0,2,3,3,1,0,0};
  if (s.canJump(ans6)) {
    cout << ">>>>> ans6 Succeeded" << endl;
  } else {
    cout << ">>>>> ans6 Failed" << endl;
  }

  vector<int> ans7 = {4,2,0,0,1,1,4,4,4,0,4,0};
  if (s.canJump(ans7)) {
    cout << ">>>>> ans7 Succeeded" << endl;
  } else {
    cout << ">>>>> ans7 Failed" << endl;
  }
  return 0;
}