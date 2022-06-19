/*
 * @Author: LetMeFly
 * @Date: 2022-06-19 10:33:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-19 10:35:58
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* p = head;
        while (p->next) {
            ListNode* next = p->next;
            if (next->val == p->val) {
                p->next = next->next;
                // delete next;
            }
            else {
                p = next;
            }
        }
        return head;
    }
};