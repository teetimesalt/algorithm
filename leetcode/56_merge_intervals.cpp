/**
https://leetcode.com/problems/merge-intervals/

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.


Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
*/
#include <algorithm>
#include <vector>
#include <iostream>

#define DEBUG

using namespace std;
using vi = vector<int>::iterator;

void print(vector<int> &vec) {
#ifdef DEBUG
  cout << "[";
  for(vi i=vec.begin(); i != vec.end() ; i++) {
    cout << *i << " ";
  }
  cout << "]"<< endl;
#endif
}

void print(vector<vector<int>> &vec) {
#ifdef DEBUG
  vector<vector<int>>::iterator vii;

  for(vii=vec.begin(); vii != vec.end() ; vii++) {
    cout << "[";
    for(vi i = (*vii).begin() ; i != (*vii).end() ; i++) {
      cout << *i << " ";
    }
    cout << "]";
  }
  cout << endl;
#endif
}

class Solution {
public:
    int min(int a, int b) {
      return a > b ? b : a;
    }

    int max(int a, int b) {
      return a > b ? a : b;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end()); //포인트
      vector<vector<int>> res;
      vector<vector<int>>::iterator vii = intervals.begin();
      vector<int> crnt = {(*vii)[0], (*vii)[1]};
      
      vii++;
      for( ; vii != intervals.end() ; vii++) {
        vector<int> &i = *vii;
        if (crnt[1] < i[0]) {
          res.push_back(crnt);
          crnt[0] = i[0]; crnt[1] = i[1];
        } else {
          crnt[0] = min(crnt[0], i[0]);
          crnt[1] = max(crnt[1], i[1]);
        }
      }
      res.push_back(crnt);
      return res;
    }
};

int main() {
  Solution s;

  vector<vector<int>> exam1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> ans1 = s.merge(exam1);
  print(ans1);

  vector<vector<int>> exam2 = {{1, 4}, {4, 5}};
  vector<vector<int>> ans2 = s.merge(exam2);
  print(ans2);

  //[[1,4],[0,4]]
  vector<vector<int>> exam3 = {{1, 4}, {0, 4}};
  vector<vector<int>> ans3 = s.merge(exam3);
  print(ans3);
  
  return 0;
}