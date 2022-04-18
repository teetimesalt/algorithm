/**
https://leetcode.com/problems/remove-duplicate-letters/

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Constraints:
1 <= s.length <= 104
s consists of lowercase English letters.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

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
    string removeDuplicateLetters(string s) {
      bool check[28] = {0};
      string ans;
      string s_ = s;
      map<char, int> m;
      stack<char> stk;
      char append;
      print("s ", s);
      
      std::sort(s_.begin(), s_.end());
      for(int i = 0 ; i < s_.length() ; i++) {
        if (m.find(s_[i]) == m.end()) {
          m[s_[i]] = 1;
        } else {
          m[s_[i]]++;
        }
      }

      for (int i = 0 ; i < s.length() ; i++) {
        print("current char ", s[i]);
        print("check[s[i]-'a'] ", check[s[i]-'a']);
        
        if (i == s.length()-1 && m[s[i]] == 1) {
          append = s[i];
          break;
        }

        if (check[s[i]-'a']) {
          m[s[i]]--;
          print("already in strack ", s[i]);
        } else {
          if (!stk.empty())
            print("stk.top() " + to_string(stk.top()) + " s[i] " + to_string(s[i]) + " m[s[i]] " + to_string(m[stk.top()]), 0);
          while(!stk.empty() && stk.top() > s[i] && m[stk.top()] != 0) {
            print("stack top ", stk.top());
            check[stk.top()-'a'] = false;
            stk.pop();
          }
          if (m[s[i]]) {
            print("pushed to stack ", s[i]);
            stk.push(s[i]);
            m[s[i]]--;
            check[s[i]-'a'] = true;
          }
        }
        map<char, int>::iterator it;
        for(it = m.begin() ; it != m.end() ; it++) {
          print("[" + to_string(it->first) + "," + to_string(it->second) + "]", 0);
        }
      }

      while(!stk.empty()) {
        ans += stk.top();
        stk.pop();
      }
      reverse(ans.begin(), ans.end());
      if (append >= 'a' && ans.find(append) == string::npos)
        ans += append;
      print("ans ", ans);
      
      return ans;
    }
};

int main() {
  Solution s;
  if (s.removeDuplicateLetters("bcabc") == "abc")
    cout << "exam1 succeeded" << endl;
  else
    cout << "exam1 failed" << endl;

  if (s.removeDuplicateLetters("cbacdcbc") == "acdb")
    cout << "exam2 succeeded" << endl;
  else
    cout << "exam2 failed" << endl;

  if (s.removeDuplicateLetters("cdadabcc") == "adbc")
    cout << "exam3 succeeded" << endl;
  else
    cout << "exam3 failed" << endl;

  if (s.removeDuplicateLetters("abacb") == "abc")
    cout <<"exam4 succeeded" << endl;
  else
    cout << "exam4 failed" << endl;

  return 0;
}