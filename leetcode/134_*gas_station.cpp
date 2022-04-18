/**
https://leetcode.com/problems/gas-station/

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

 

Example 1:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
*/



#include <iostream>
#include <string>
#include <vector>

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
    bool canTravelFrom(int from, vector<int>& gas, vector<int>& cost) {
      print("canTravelFrom ", from);
      int sz = gas.size();
      int index = from;
      int gas_storage = 0;
      for(int i = 0 ; i < sz ; i++) {
        gas_storage = gas_storage + gas[index] - cost[index];
        print("gas_storage ", gas_storage);
        index = (index+1) % sz;
        print("index ", index);

        if (gas_storage <= 0 && index != from) {
          return false;
        }
      }

      print("Retrn true", 0);
      return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int sz = gas.size();
      unsigned long long sum_gas = 0;
      unsigned long long sum_cost = 0;
      int gas_storage = 0;
      int index = 0;
      for(int i = 0 ; i < sz ; i++) {
        sum_gas += gas[i];
        sum_cost += cost[i];
        gas_storage = gas_storage + gas[i] - cost[i];
        print("i ", i);
        print("gas ", gas[i]);
        print("cost ", cost[i]);
        print("gas_storage ", gas_storage);
        if (gas_storage < 0) {
          gas_storage = 0;
          index = i + 1;
        }
      }
      if (sum_gas < sum_cost)
        return -1;

      return index;
    }
};

int main() {
  Solution s;

  vector<int> s1 = {1,2,3,4,5};
  vector<int> c1 = {3,4,5,1,2};
  int ans1 = s.canCompleteCircuit(s1, c1);
  cout << "exam1 " << ans1 << endl;

  vector<int> s2 = {2,3,4};
  vector<int> c2 = {3,4,3};
  int ans2 = s.canCompleteCircuit(s2, c2);
  cout << "exam2 " << ans2 << endl;

  vector<int> s3 = {5, 1, 2, 3, 4};
  vector<int> c3 = {4, 4, 1, 5, 1};
  int ans3 = s.canCompleteCircuit(s3, c3);
  cout << "exam3 " << ans3 << endl; //4
}