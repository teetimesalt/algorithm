/**
https://leetcode.com/problems/sort-list/

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []
*/
#define DEBUG
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    ListNode* mergeSortList(ListNode* l, ListNode* r) {
      ListNode *res = nullptr;
      if (l && r) {
        cout << "mergeSortList l:"; print(l);
        cout << "mergeSortList r:"; print(r);
        if (l->val > r->val) {
          ListNode *tmp = l;
          res = r;
          res->next = mergeSortList(l, r->next);
        } else {
          res = l;
          res->next = mergeSortList(l->next, r);
        }
      }
      if (l == nullptr) res = r;
      if (r == nullptr) res = l;
      
      return res;
    }

    void print(ListNode *head) {
#ifdef DEBUG
      ListNode *p = head;
      while(p) {
        cout << p->val << " ";
        p = p->next;
      }
      cout << endl;
#endif
    }

    ListNode* sortList(ListNode* head) {
      print(head);
      if (head && head->next == nullptr) {
        return head;
      }
      ListNode *half = nullptr, *slow = head, *fast = head;
      while(fast != nullptr && fast->next != nullptr) {
        half = slow;
        slow = slow->next;
        fast = fast->next->next;
      }

      print(half);
      if (half) {
        half->next = nullptr;
      } else {
        return half;
      }
      ListNode* l = sortList(head);
      if (l == nullptr) l = head;
      ListNode* r = sortList(slow);
      if (r == nullptr) r = slow;

      return mergeSortList(l, r);
    }
};

int main() {
  ListNode *node_3 = new ListNode(3);
  ListNode *node_1 = new ListNode(1, node_3);
  ListNode *node_2 = new ListNode(2, node_1);
  ListNode *head = new ListNode(4, node_2);
  Solution s;
  ListNode* n = s.sortList(head);
  cout << "Exam1 ===============================" << endl;
  s.print(n);
  delete node_3, node_1, node_2, head;

  //[-1,5,3,4,0]
  ListNode *node_5 = new ListNode(0);
  ListNode *node_4 = new ListNode(4, node_5);
  node_3 = new ListNode(3, node_4);
  node_2 = new ListNode(5, node_3);
  head = new ListNode(-1, node_2);
  n = s.sortList(head);
  cout << "Exam2 ===============================" << endl;
  s.print(n);
  delete node_5, node_4, node_3, node_1, node_2, head;

  //[1]
  head = new ListNode(1);
  n = s.sortList(head);
  cout << "Exam3 ===============================" << endl;
  s.print(n);
  delete head;
  
  return 0;
}