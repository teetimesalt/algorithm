/**
https://leetcode.com/problems/russian-doll-envelopes/

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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

/**
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [] (const vector <int> & a, const vector <int> & b) {return a[0] < b[0] or (a[0] == b[0] and b[1] < a[1]);});
        
        vector <int> sub;

        for(auto e : envelopes){
            int x = e[1];
            if(sub.size() == 0 or sub[sub.size() - 1] < x)
                sub.push_back(x);
            else{
                auto it = lower_bound(sub.begin(), sub.end(), x);
                *it = x;
                
            }
        }
        return sub.size();
    }
};
*/

/**
class Solution {
    int[] dp;
    
    public int maxEnvelopes(int[][] envelopes) {
        int[][] newEnvelopes = new int[envelopes.length+1][2];
        
        boolean[] visited = new boolean[newEnvelopes.length];
        dp = new int[visited.length];
        Arrays.fill(dp,-1);
        
        newEnvelopes[0][0]= Integer.MAX_VALUE;
        newEnvelopes[0][1]= Integer.MAX_VALUE;
        
        for(int i=1; i<newEnvelopes.length;i++)
            newEnvelopes[i] = envelopes[i-1];
        
        int ans = 0;
        ans = Math.max(ans, getRussianDoll(newEnvelopes,visited,0));
        
        return ans;
    }
    
    public int getRussianDoll(int[][] envelopes, boolean[] visited, int start){
        if(dp[start]!=-1) return dp[start];
        
        int ret = 0;
        
        for(int i=0; i<envelopes.length; i++){
            if(visited[i]) continue;
            if(envelopes[start][0]>envelopes[i][0]
              &&envelopes[start][1]>envelopes[i][1]){
                visited[i] = true;
                ret = Math.max(getRussianDoll(envelopes,visited,i)+1,ret);
                visited[i] = false;
            }
        }
        return dp[start]=ret;
    }
}
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      sort(envelopes.begin(), envelopes.end(), [] (const vector<int> &a, const vector<int> &b) {
        if (a[0] != b[0])
          return a[0] < b[0];
        return b[1] < a[1];
      });
      print("sorted:", envelopes);
      vector<int> e(envelopes.size(), 0);
      int count = 0;
      for (int i = 0 ; i < envelopes.size() ; i++) {
        int start = 0, end = count;
        while(start < end) {
          int mid = (start + end) / 2;
          cout << "mid : " << mid << ", e[mid] : " << e[mid] << " envelopes[i][1] : " << envelopes[i][1] << endl;
          if (e[mid] < envelopes[i][1]) {
            start = mid + 1;
          } else {
            end = mid;
          }
        }
        e[start] = envelopes[i][1];
        if (start == count) {
          count++;
        }
        print("e:", e);
      }
      return count;
    }
};

int main() {
  // [[5,4],[6,4],[6,7],[2,3]]
  vector<vector<int>> exam1{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
  Solution s;
  cout << "exam1 " << s.maxEnvelopes(exam1) << endl;

  vector<vector<int>> exam2{{1, 1}, {1, 1}, {1, 1}};
  cout << "exam2 " << s.maxEnvelopes(exam2) << endl;

  //[[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]
  vector<vector<int>> exam3{{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370}, {6, 360}, {7, 380}};
  cout << "exam3 " << s.maxEnvelopes(exam3) << endl;
  return 0;
}