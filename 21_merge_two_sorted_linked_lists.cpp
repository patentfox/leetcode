#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* current = head;
    while (l1 != nullptr && l2 != nullptr) {
      ListNode* temp = nullptr;
      if (l1->val <= l2->val) {
        temp = l1;
        l1 = l1->next;
      } else {
        temp = l2;
        l2 = l2->next;
      }
      if (head == nullptr) {
        head = temp;
        current = head;
      } else {
        current->next = temp;
        current = current->next;
      }
    }
    if (head == nullptr) {
      return l1 == nullptr ? l2 : l1;
    }
    current->next = l1 == nullptr ? l2 : l1;
    return head;
  }
};
