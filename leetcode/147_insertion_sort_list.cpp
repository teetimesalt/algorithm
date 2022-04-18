/**
https://leetcode.com/problems/insertion-sort-list/

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

Example 1
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
*/

#include <iostream>
#include <string>

//#define DEBUG

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef struct ListNode ListNode;

void print(string msg, ListNode *head) {
#ifdef DEBUG
  cout << "In print " << msg << " :";
  ListNode *iter = head;
  while(iter != nullptr) {
    cout << iter->val << " ";
    iter = iter->next;
  }
  cout << endl;
#endif
}

void print_node(string msg, ListNode *node) {
#ifdef DEBUG
  cout << "In print node " << msg << ":";
  if (node)
    cout << node->val << endl;
  else
    cout << "nullptr" << endl;
#endif
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode *new_head = head;
      ListNode *crnt = head;
      ListNode *next_crnt = head->next;

      while(crnt != nullptr) {
        print_node("crnt", crnt); print_node("next crnt", next_crnt);
        print("new_head", new_head);

        ListNode *iter = new_head;
        ListNode *prev = iter;
        bool insertion = false;
        while(iter != nullptr && iter != next_crnt) {
          print_node("iter", iter);
          print_node("prev", prev);
          print_node("new_head", new_head);
          if (crnt->val < iter->val && !insertion) {
            if (iter == new_head)
              new_head = crnt;
            else
              prev->next = crnt; print_node("prev->next", prev->next);
            crnt->next = iter; print_node("crnt->next", crnt->next);
            insertion = true;
          }
          if (insertion && iter->next == crnt)
            iter->next = next_crnt;
          prev = iter;
          iter = iter->next;
        }
        insertion = false;
        crnt = next_crnt;
        if (next_crnt)
          next_crnt = next_crnt->next;
        print("at tail:", new_head);
      }

      return new_head;
    }
};

int main() {
  //Input: head = [4,2,1,3]
  //Output: [1,2,3,4]
  ListNode *node_3 = new ListNode(3);
  ListNode *node_1 = new ListNode(1, node_3);
  ListNode *node_2 = new ListNode(2, node_1);
  ListNode *node_4 = new ListNode(4, node_2);

  print("Exam1:", node_4);
  Solution s;
  ListNode *ans = s.insertionSortList(node_4);
  print("Exam1 ans:", ans);

  delete node_3;
  delete node_1;
  delete node_2;
  delete node_4;

  //Input: head = [-1,5,3,4,0]
  //Output: [-1,0,3,4,5]
  ListNode *node_0 = new ListNode(0);
  node_4 = new ListNode(4, node_0);
  node_3 = new ListNode(3, node_4);
  ListNode *node_5 = new ListNode(5, node_3);
  ListNode *node__1 = new ListNode(-1, node_5);

  print("Exam2:", node__1);
  ans = s.insertionSortList(node__1);
  print("Exam2 ans:", ans);
  
  return 0;
}