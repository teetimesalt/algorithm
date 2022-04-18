/*
https://leetcode.com/problems/valid-anagram/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
**/

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

void print(string &&msg, string s) {
#ifdef DEBUG
  cout << msg << " " << s << endl;
#endif
}

void print_vec(string &&msg, vector<char> &v) {
#ifdef DEBUG
  cout << msg << " ";
  vector<char>::iterator it;
  for(it = v.begin() ; it != v.end() ; it++) {
    cout << *it;
  }
  cout << endl;
#endif
}
class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<char> vec_s(s.begin(), s.end());
    vector<char> vec_t(t.begin(), t.end());
    
    sort(vec_s.begin(), vec_s.end());
    sort(vec_t.begin(), vec_t.end());
    print_vec("vec_s", vec_s);
    print_vec("vec_t", vec_t);

    return string(vec_s.begin(), vec_s.end()) == string(vec_t.begin(), vec_t.end());
  }
};

int main() {
  Solution s;
  if (s.isAnagram("anagram", "nagaram"))
    cout << "Succeeded" << endl;
  else
    cout << "Failed" << endl;

  if (!s.isAnagram("rat", "car"))
    cout << "Succeeded" << endl;
  else
    cout << "Failed" << endl;
  
  return 0;
}