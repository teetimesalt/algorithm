/**
https://leetcode.com/problems/k-closest-points-to-origin/

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
*/

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define DEBUG

void print(string&& msg, vector<int> &point) {
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

typedef struct Distance {
  int index;
  int distance;
} Distance;

struct Compare {
  bool operator()(Distance &a, Distance &b) {
    print("Distance a ", a.distance);
    print("Distance b ", b.distance);
    return a.distance > b.distance;
  }
};

class Solution {
public:
    int caculateDistance(int &a, int &b) {
      return pow(abs(a-0), 2) + pow(abs(b-0), 2);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      vector<vector<int>> ans;
      priority_queue<Distance, vector<Distance>, Compare> sortedPoints;
      for(int i = 0; i < points.size() ; i++) {
        vector<int> point = points[i];
        print("index " + to_string(i), point);
        print("index " + to_string(i), caculateDistance(point[0], point[1]));
        sortedPoints.push({i, caculateDistance(point[0], point[1])});
      }

      for(int i = 0 ; i < k ; i++) {
        Distance d = sortedPoints.top();
        sortedPoints.pop();
        ans.push_back(points[d.index]);
      }

      print("ans: ", ans);
      return ans;
    }
};

int main() {
  Solution s;
  
  vector<vector<int>> exam1 = {{1,3}, {-2, 2}};
  s.kClosest(exam1, 1);

  //[3,3],[5,-1],[-2,4]], k = 2
  vector<vector<int>> exam2 = {{3,3}, {5,-1}, {-2,4}};
  s.kClosest(exam2, 2);

  vector<vector<int>> exam3 = {{-5,4},{-6,-5},{4,6}};
  s.kClosest(exam3, 2);
  
  return 0;
}