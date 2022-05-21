/*
 * @Author: LetMeFly
 * @Date: 2022-05-12 09:45:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-12 09:55:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

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
class Solution {
public:
    ListNode* swapPairs(ListNode* first) {
        ListNode* head = new ListNode(0, first);
        ListNode* last = head;
        while (first && first->next) {
            // change next
            last->next = first->next;
            first->next = first->next->next;
            last->next->next = first;
            // change node
            last = first;
            first = first->next;
        }
        return head->next;
    }
};