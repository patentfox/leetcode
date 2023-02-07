//
//  83_remove_duplicates_from_sorted_list.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 02.07.21.
//


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *prev = head, *current = head->next;
        while (current != nullptr) {
            if(current->val == prev->val) {
                prev->next = current->next;
                ListNode* temp = current;
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};
