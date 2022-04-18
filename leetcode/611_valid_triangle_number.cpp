/**
https://leetcode.com/problems/valid-triangle-number/

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Example 2:
Input: nums = [4,2,3,4]
Output: 4
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define DEBUG

void print(string &&msg) {
#ifdef DEBUG
  cout << msg << endl;
#endif
}

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

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
      int ans = 0;
      if (nums.size() < 3) {
        return ans;
      }
      sort(nums.begin(), nums.end());

      for(int i = 2 ; i < nums.size() ; i++) {
        int l = 0;
        int h = i-1;
        int n = nums.size();
        while (l < h) {
          print("nums[i] " + to_string(nums[i]) + " nums[l] " + to_string(nums[l]) + " nums[h] " + to_string(nums[h]));
          if (nums[i] < nums[l] + nums[h]) {
            ans += (h-l);
            h--;
          } else {
            l++;
          }
        }
      }
      
      return ans;
    }
};

int main() {
  Solution s;

  vector<int> exam1 = {2,2,3,4};
  if (s.triangleNumber(exam1) == 3) {
    cout << "Exam1 succeeded" << endl;
  } else {
    cout << "Exam1 failed" << endl;
  }

  vector<int> exam2 = {4,2,3,4};
  if (s.triangleNumber(exam2) == 4) {
    cout << "Exam2 succeeded" << endl;
  } else {
    cout << "Exam2 failed" << endl;
  }

  vector<int> exam3 = {1};
  if (s.triangleNumber(exam3) == 0) {
    cout << "Exam3 succeeded" << endl;
  } else {
    cout << "Exam3 failed" << endl;
  }

  // vector<int> exam4 = {33,97,81,65,30,58,83,83,66,85,78,40,51,61,86,94,42,17,35,18,45,27,56,78,36,97,6,51,76,26,68,68,61,87,13,98,93,80,24,34,19,90,85,89,83,15,41,52,25,16,61,51,19,6,40,79,25,88,65,85,0,42,78,27,30,68,47,67,40,26,15,72,20,45,88,82,12,82,95,1,46,56,83,20,65,39,13,92,36,99,74,50,46,8,27,45,36,55,50,0};
  // if (s.triangleNumber(exam4) == 0) {
  //   cout << "Exam4 succeeded" << endl;
  // } else {
  //   cout << "Exam4 failed" << endl;
  // }

  // vector<int> exam5 = {71,69,81,80,80,27,92,90,43,15,31,58,80,32,46,51,85,41,6,27,14,89,45,96,63,26,20,31,93,9,7,44,2,40,51,59,64,85,71,33,44,13,14,5,71,58,8,51,77,25,24,38,19,11,43,95,13,63,100,64,95,64,37,15,54,97,80,64,41,40,72,22,69,45,23,61,8,4,18,90,62,31,43,2,41,4,92,22,10,21,86,20,53,44,27,88,10,82,37,88};
  return 0;
}