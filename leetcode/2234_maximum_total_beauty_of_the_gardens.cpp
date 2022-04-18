/**
https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/

Alice is a caretaker of n gardens and she wants to plant flowers to maximize the total beauty of all her gardens.

You are given a 0-indexed integer array flowers of size n, where flowers[i] is the number of flowers already planted in the ith garden. Flowers that are already planted cannot be removed. You are then given another integer newFlowers, which is the maximum number of flowers that Alice can additionally plant. You are also given the integers target, full, and partial.

A garden is considered complete if it has at least target flowers. The total beauty of the gardens is then determined as the sum of the following:

The number of complete gardens multiplied by full.
The minimum number of flowers in any of the incomplete gardens multiplied by partial. If there are no incomplete gardens, then this value will be 0.
Return the maximum total beauty that Alice can obtain after planting at most newFlowers flowers.

Example 1:
Input: flowers = [1,3,1,1], newFlowers = 7, target = 6, full = 12, partial = 1
Output: 14
Explanation: Alice can plant
- 2 flowers in the 0th garden
- 3 flowers in the 1st garden
- 1 flower in the 2nd garden
- 1 flower in the 3rd garden
The gardens will then be [3,6,2,2]. She planted a total of 2 + 3 + 1 + 1 = 7 flowers.
There is 1 garden that is complete.
The minimum number of flowers in the incomplete gardens is 2.
Thus, the total beauty is 1 * 12 + 2 * 1 = 12 + 2 = 14.
No other way of planting flowers can obtain a total beauty higher than 14.

Example 2:
Input: flowers = [2,4,5,3], newFlowers = 10, target = 5, full = 2, partial = 6
Output: 30
Explanation: Alice can plant
- 3 flowers in the 0th garden
- 0 flowers in the 1st garden
- 0 flowers in the 2nd garden
- 2 flowers in the 3rd garden
The gardens will then be [5,4,5,5]. She planted a total of 3 + 0 + 0 + 2 = 5 flowers.
There are 3 gardens that are complete.
The minimum number of flowers in the incomplete gardens is 4.
Thus, the total beauty is 3 * 2 + 4 * 6 = 6 + 24 = 30.
No other way of planting flowers can obtain a total beauty higher than 30.
Note that Alice could make all the gardens complete but in this case, she would obtain a lower total beauty.
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

void print(string &&msg, vector<long long> &points) {
#ifdef DEBUG
  cout << msg << " ";
  vector<long long>::iterator it;

  for(it = points.begin() ; it != points.end() ; it++) {
    cout <<  " " << *it;
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
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
      long long ans = 0;
      sort(flowers.begin(), flowers.end(), [](const int &a, const int &b){
        return b < a; 
      });
      print("sorted", flowers);
      int start = 0, end = flowers.size();
      int mid = (start + end) / 2;
      while(start < end) {
        print("start", start);
        print("mid", mid);
        print("end", end);
        if (mid == target-1) {
          print("start", start);
          break;
        }
          
        if (mid < full) {
          start = mid + 1;
        } else {
          end = mid;
        }
        mid = (start + end) / 2;
      }
      return ans;
    }
};
*/

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        const long long n = flowers.size();
        std::sort(flowers.begin(), flowers.end());
        std::vector<long long> costs(n, 0);
        // special case 1: all gardens are already complete
        if(flowers[0] >= target){
            return full * n;
        }
        flowers[0] = std::min(flowers[0], target); // cap it
        long long last_partial = 0;
        for(long long i = 1; i < n; ++i){
            if(flowers[i] >= target){
                flowers[i] = target;
            } else{
                last_partial = i;
            }
            costs[i] = costs[i - 1] + (flowers[i] - flowers[i - 1]) * i;
        }
        print("cost", costs);
        // special case 2: all gardens can be complete
        if(costs.back() + n * (target - flowers.back()) <= newFlowers){
            return std::max(full * n, full * (n - 1) + partial * static_cast<long long>(target - 1));
        }
        long long res = 0;
		// --- ALL code above is the same as the binary-search solution --- //
        for(auto first_complete = last_partial + 1, best_effort = last_partial; first_complete >= 0; --first_complete){
            print("The first step in the main loop, ", 0);
            print("first_complete", first_complete);
            print("best_effor", best_effort);
            print("n", n);
            newFlowers -= first_complete == n ? 0 : (target - flowers[first_complete]);
            print("newFlowers ", newFlowers);
            if(newFlowers < 0){
                break;
            }
            print("minimum : best_effort, first_complete-1", 0);
            print("first_complete-1", first_complete - 1);
            best_effort = std::min(best_effort, first_complete - 1);
            print("best effort", best_effort);
            // try to fill the first [0, first_complete) gardens to their maximum partial 
			// -> instead of binary search, we use another pointer here
            print("costs[best_effort]", costs[best_effort]);
            print("newFlowers", newFlowers);
            while(best_effort >= 0 && costs[best_effort] > newFlowers){
                print("moving best_effort", 0);
                --best_effort;
            }
            print("After moving points best_effort", best_effort);
            // we can only maximize [0, best_effort] gardens
            const auto extra = (newFlowers - costs[best_effort]) / (best_effort + 1);
            print("extra", extra);
            res = std::max(res, full * (n - first_complete) + partial * (extra + flowers[best_effort]));
        }
        return res;
        
    }
};
int main() {
  Solution s;
  vector<int> e1 = {1,3,1,1};
  cout << "exam1: " << s.maximumBeauty(e1, 7, 6, 12, 1) << endl;

  vector<int> e2 = {2,4,5,3};
  cout << "exam1: " << s.maximumBeauty(e2, 10, 5, 2, 6) << endl;
  return 0;
}