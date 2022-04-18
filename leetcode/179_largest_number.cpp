/**
https://leetcode.com/problems/largest-number/

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.


Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

const int MAX_DEC = 1000000000;

#define DEBUG

void print(string&& msg, int value) {
#ifdef DEBUG
  cout << msg << " : " << value << endl;
#endif
}

void print_vec(string&& msg, vector<int> &nums) {
#ifdef DEBUG
  cout << msg << " [";
  vector<int>::iterator it;
  for(it = nums.begin() ; it != nums.end() ; it++) {
    cout << *it << ",";
  }
  cout << "]" << endl;
#endif
}

map<int, vector<int>> num_map;
vector<int> convertVector(int &n) {
  print("convertVector", n);
  vector<int> ans = num_map[n];
  if (ans.size() == 0) {
    if (n == 0) {
      ans.push_back(0);
      num_map[n] = ans;
    } else {
      vector<int>::iterator it;

      int tmp = n;
      int tmp_dec = MAX_DEC;
      do {
        if (tmp / tmp_dec != 0 || ans.size() > 0) {
          ans.push_back(tmp / tmp_dec);
        }
        tmp %= tmp_dec;
        tmp_dec /= 10;
      } while(tmp_dec > 0);
      num_map[n] = ans;
    }
  }
  
  print_vec("convertVector nums ", ans);
  return ans;
}

bool myCompare(int a, int b) {
  // Using to_string fundtion would be faster
  vector<int> &&vec_a = convertVector(a);
  vector<int> &&vec_b = convertVector(b);
  if (vec_a.size() == vec_b.size())
    return a > b;

  unsigned long long numA = a * pow(10, vec_b.size()) + b;
  unsigned long long numB = b * pow(10, vec_a.size()) + a;
  print("numA :", numA);
  print("numB :", numB);

  if (numA > numB) return true;
  return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
      num_map.clear();
      string ans;
      sort(nums.begin(), nums.end(), myCompare);
      print_vec("after sort:", nums);

      vector<int>::iterator it;
      for(it = nums.begin() ; it != nums.end() ; it++) {
        ans += to_string(*it);
      }
      if (ans[0] == '0')
        return "0";

      return ans;
    }
};

int main() {
  Solution s;

  vector<int> exam1 = {10, 2};
  cout << s.largestNumber(exam1) << endl;

  vector<int> exam2 = {3, 30, 34, 5, 9};
  cout << s.largestNumber(exam2) << endl;

  vector<int> exam3 = {111311, 1113};
  cout << s.largestNumber(exam3) << endl;

  vector<int> exam4 = {34323,3432};
  cout << s.largestNumber(exam4) << endl;

  vector<int> exam5 = {0,0};
  cout << s.largestNumber(exam5) << endl;
}