/**
https://leetcode.com/problems/remove-k-digits/
A) https://leetcode.com/problems/remove-k-digits/discuss/1779458/C%2B%2B-oror-Easy-To-Understand-oror-Stack-oror-Short-and-Simple

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/**
[정답풀이]
k 가 0이 될 때까지 loop 을 돌면서 숫자를 하나하나 빼야함
만약 num.length가 k와 같다면 0을 반환
std::stoi 함수 사용

int min 을 유지해야 하는가?
sliding 기법을 사용할 수 없음 (구간이 아님)

1. 첫 번째 루프
2. k 만큼의 구간을 정해 그 중 가장 작은 숫자를 골라냄
3. 작은 숫자로 선택된 앞 숫자들을 모두 제거

예 : 1432219 k=3
length=7,index=0 {143}2219 중 가장 작은 1
length=6,index=1 1{432}219 중 가장 작은 2. 2까지의 4, 3을 제거. index=4
length=5,index=4 12219  length-index가 k보다 작으므로 구간을 2로?
length=5,index=0 {12}219 중 가장 작은 1
length=5,index=1 1{22}19 중 작은 2. 2를 하나 삭제 1219
length=origin_length-k 이므로 끝
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <stdlib.h>

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
    string removeKdigits(string num, int k) {
      if (num.size() <= k)
        return "0";
      if (k == 0)
        return num;

      string res;
      int sz = num.size();
      stack<int> st;
      int k_ = k;
      st.push(num[0] - '0');
      for(int i = 1 ; i < sz ; i++) {
        int cur = num[i] - '0';
        while (!st.empty() && st.top() > cur && k_ > 0) {
          st.pop();
          k_--;
        }
        st.push(cur);

        if (st.size() == 1 && cur == 0) {
          print("st.top() ", st.top());
          st.pop();
        }
      }

      while(k_ > 0 && !st.empty()) {
        k_--;
        st.pop();
      }

      while(!st.empty()) {
        res += to_string(st.top());
        st.pop();
      }

      reverse(res.begin(), res.end());
      if (res.empty())
        res = "0";

      return res;
    }
};

int main() {
  Solution s;

  string ans6 = s.removeKdigits("10001", 4);
  if (ans6 == "0") {
    cout << "ans6 " << ans6 << endl;
  } else {
    cout << "ans6 Failed" << endl;
  }

  string ans5 = s.removeKdigits("10", 1);
  if (ans5 == "0") {
    cout << "ans5 " << ans5 << endl;
  } else {
    cout << "ans5 Failed" << endl;
  }

  string ans1 = s.removeKdigits("1432219", 3);
  if (ans1 == "1219") {
    cout << "ans1 " << ans1 << endl;
  } else {
    cout << "ans1 Failed" << endl;
  }

  string ans2 = s.removeKdigits("10200", 1);
  if (ans2 == "200") {
    cout << "ans2 " << ans2 << endl;
  } else {
    cout << "ans2 Failed" << endl;
  }

  string ans3 = s.removeKdigits("10", 2);
  if (ans3 == "0") {
    cout << "ans3 " << ans3 << endl;
  } else {
    cout << "ans3 Failed" << endl;
  }

  string ans4 = s.removeKdigits("12345", 2);
  if (ans4 == "123") {
    cout << "ans4 " << ans4 << endl;
  } else {
    cout << "ans4 Failed" << endl;
  }
}