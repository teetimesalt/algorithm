/**
https://leetcode.com/problems/integer-replacement/

Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

Example 1:
Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1

Example 2:
Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1

Example 3:
Input: n = 4
Output: 2
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    map<unsigned long, int> m;
    map<unsigned long, int>::iterator it;

    int min(int a, int b) {
      if (a > b)
        return b;
      return a;
    }
    int doIntegerReplacement(unsigned long n) {
      it = m.find(n);
      if (it != m.end()) {
        cout << "cached result" << endl;
        return m[n];
      }

      if (n == 1)
        return 0;
      int count = 0;
      if (n % 2 == 0) {
        count = 1 + doIntegerReplacement(n/2);
      } else {
        count = 1 + min(doIntegerReplacement(n+1), doIntegerReplacement(n-1));
      }
      if (it != m.end())
        m[n] = count;
      cout << "In doIntegerReplacement n : " << n << " count : " << count << endl;
      return count;
    }
    int integerReplacement(int n) {
      
      cout << "integerReplacement n " << n << endl;
      if (n == 1)
        return 0;

      m[1] = 0;
      unsigned long n_ = n; // prevent overflow
      if (n % 2 == 0) {
        return doIntegerReplacement(n);
      } else {
        return 1 + min(doIntegerReplacement(n+1), doIntegerReplacement(n-1));
      }
      return -1;
    }
};

int main() {
  Solution s;

/*
  if (s.integerReplacement(8) == 3) {
    cout << "Exam1 succeeded" << endl;
  } else {
    cout << "Exam1 failed" << endl;
  }

  if (s.integerReplacement(7) == 4) {
    cout << "Exam2 succeeded" << endl;
  } else {
    cout << "Exam2 failed" << endl;
  }

  if (s.integerReplacement(4) == 2) {
    cout << "Exam3 succeeded" << endl;
  } else {
    cout << "Exam3 failed" << endl;
  }

  if (s.integerReplacement(65535) == 17) {
    cout << "Exam4 succeeded" << endl;
  } else {
    cout << "Exam4 failed" << endl;
  }

  if (s.integerReplacement(101010101) == 10) {
    cout << "Exam5 succeeded" << endl;
  } else {
    cout << "Exam5 failed" << endl;
  }
*/
  if (s.integerReplacement(3) == 2) {
    cout << "Exam6 succeeded" << endl;
  } else {
    cout << "Exam6 failed" << endl;
  }
}