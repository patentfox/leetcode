// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int a_size = getSize(headA);
    int b_size = getSize(headB);
    if (a_size > b_size) {
      headA = moveAhead(headA, a_size - b_size);
    } else {
      headB = moveAhead(headB, b_size - a_size);
    }
    while (headA != headB) {
      if (headA == nullptr || headB == nullptr) {
        return nullptr;
      }
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }

 private:
  int getSize(ListNode *head) {
    int sz = 0;
    while (head != nullptr) {
      head = head->next;
      ++sz;
    }
    return sz;
  }
  ListNode *moveAhead(ListNode *node, int count) {
    while (count--) {
      node = node->next;
    }
    return node;
  }
};