/**
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

*/

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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ans = 0;
      int min_index = -1, max_index = -1;

      for(int i = 0 ; i < prices.size() ; i++) {
        print("i", i);
        print("prices[i]", prices[i]);
        if (max_index > 0 && prices[i] < prices[max_index]) {
          print("sell", 0);
          ans += prices[max_index] - prices[min_index];
          min_index = i;
          max_index = -1;
          print("min_index", i);
          print("ans", ans);
        }

        if (min_index == -1) {
          min_index = i;
        }
        
        if (min_index < i && prices[i] < prices[min_index]) {
          min_index = i;
          max_index = -1;
        }

        if (min_index != -1 && min_index < i) {
          if (max_index == -1) {
            max_index = i;
          }
          if (prices[max_index] < prices[i]) {
            max_index = i;
          }
        }

        if (min_index > -1)
          print("min", prices[min_index]);
        if (max_index > -1)
          print("max", prices[max_index]);
      }

      print("ans ", ans);
      print("max_index ", max_index);
      print("min_index ", min_index);
      if (max_index > -1 && min_index > -1) {
        ans += prices[max_index] - prices[min_index];
      }
      return ans;
    }
};

int main() {
  Solution s;
  vector<int> exam1 = {7,1,5,3,6,4};
  int ans = s.maxProfit(exam1);
  cout << "exam1 : " << ans << endl;

  vector<int> exam2 = {1,2,3,4,5};
  int ans2 =  s.maxProfit(exam2);
  cout << "exam2 : " << ans2 << endl;

  vector<int> exam3 = {7,6,4,3,1};
  int ans3 = s.maxProfit(exam3);
  cout << "exam3 : " << ans3 << endl;

  vector<int> exam4 = {6,1,3,2,4,7}; // 1-3 : 2, 2-7 : 5
  int ans4 = s.maxProfit(exam4);
  cout << "exam4 : " << ans4 << endl;

            
  return 0;
}