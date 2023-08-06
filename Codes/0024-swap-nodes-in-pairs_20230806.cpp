/*
 * @Author: LetMeFly
 * @Date: 2023-08-06 09:58:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-06 10:04:54
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
    ListNode* swapPairs(ListNode* p) {
        ListNode* head = new ListNode(0, p);
        p = head;
        while (p->next && p->next->next) {
            ListNode* first = p->next, *second = first->next, *third = second->next;
            p->next = second, first->next = third, second->next = first;
            p = first;
        }
        return head->next;
    }
};