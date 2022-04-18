/**
https://leetcode.com/problems/task-scheduler/

Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

Example 2:
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.

Example 3:
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 
Constraints:
1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define DEBUG

typedef struct Task {
  char c;
  int size;
} Task;

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

void print(string &&msg, vector<Task> &schedule) {
#ifdef DEBUG
  cout << msg << " ";
  vector<Task>::iterator it;

  for(it = schedule.begin() ; it != schedule.end() ; it++) {
    cout << "(" << it->c << "," << it->size << ") "; 
  }
  cout << endl;
#endif
}

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

void print(string &&msg, Task& v) {
#ifdef DEBUG
  cout << msg << " " << v.c << " " << v.size << endl;
#endif
}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      if (n == 0)
        return tasks.size();
      int ans = 0;
      sort(tasks.begin(), tasks.end());
      print("sorted tasks ", tasks);

      Task currentTask{tasks[0], 1};
      struct TaskCompare {
        bool operator() (Task &a, Task &b) {
          return a.size < b.size;
        }
      };
      priority_queue <Task, vector<Task>, TaskCompare> pq;

      for(int i = 1 ; i < tasks.size() ; i++) {
        if (currentTask.c == tasks[i]) {
          currentTask.size++;
        } else {
          pq.push(currentTask);
          currentTask = Task{tasks[i], 1};
        }
      }
      pq.push(currentTask);

      vector<Task> sched;
      int offset = 0;

      print("==== main loop start ====", 0);
      while (!pq.empty()) {
        Task t = pq.top();
        print("t.c", t.c);
        print("t.size", t.size);
        pq.pop();
        t.size -= 1;
        if (t.size > 0) {
          sched.push_back(t);
        }
        offset++;
        ans++;
        print("ans", ans);
        print("pq.size()", pq.size());
        if (offset == n+1 || pq.empty()) {
          print("offset", offset);
          if (offset != n+1) {
            if (sched.empty()) {
              print("sched is empty", -5);
              break;
            }
            print("idle", n+1-offset);
            ans += (n+1-offset);
          }
          offset = 0;
          print("==== inner loop start ====", 0);
          vector<Task>::iterator it;
          for(it = sched.begin() ; it != sched.end() ; it++) {
            pq.push(*it);
          }
          sched.erase(sched.begin(), sched.begin() + sched.size());
          print("finished small loop pq size is", (int)pq.size());
          continue;
        }
      }

      return ans;
    }
};

int main() {
  Solution s;
  
  // Input: tasks = ["A","A","A","B","B","B"], n = 2
  // vector<char> exam1 = {'A', 'A', 'A', 'B', 'B', 'B'};
  // int ans1 = s.leastInterval(exam1, 2);
  // cout << "exam1 " << ans1 << endl;

  // vector<char> exam2 = {'A', 'A', 'A', 'B', 'B', 'B'};
  // int ans2 = s.leastInterval(exam2, 0);
  // cout << "exam2 " << ans2 << endl;

  // // ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
  // vector<char> exam3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  // int ans3 = s.leastInterval(exam3, 2);
  // cout << "exam3 " << ans3 << endl;

  // 4
  vector<char> exam4 = {'A', 'B', 'A'};
  int ans4 = s.leastInterval(exam4, 2);
  cout << "exam4 " << ans4 << endl;

  return 0;
}