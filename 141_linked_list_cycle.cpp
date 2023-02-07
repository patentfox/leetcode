// https://leetcode.com/problems/linked-list-cycle/

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
  bool hasCycle(ListNode *head) {
    if (head == nullptr) {
      return false;
    }
    ListNode *slow = head, *fast = head;
    do {
      slow = slow->next;
      if (fast->next == nullptr) {
        return false;
      }
      fast = fast->next->next;
    } while (slow != fast && fast != nullptr);
    return slow == fast;
  }
};