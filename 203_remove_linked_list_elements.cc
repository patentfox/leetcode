// https://leetcode.com/problems/remove-linked-list-elements/


struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    while (head != nullptr && head->val == val) {
      ListNode* temp = head;
      head = head->next;
      delete temp;
    }
    ListNode* current = head;
    while (current != nullptr && current->next != nullptr) {
      if(current->next->val == val) {
        ListNode* tempNode = current->next;
        current->next = tempNode->next;
        delete tempNode;
      } else {
        current = current->next;
      }
    }
    return head;
  }
};