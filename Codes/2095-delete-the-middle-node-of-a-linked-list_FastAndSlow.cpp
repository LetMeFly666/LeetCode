/*
 * @Author: LetMeFly
 * @Date: 2026-06-15 17:02:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-15 17:19:37
 */
#ifdef _DEBUG
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head, *last = head;
        while (fast && fast->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (last == head) {
            return nullptr;
        }
        last->next = slow->next;
        delete slow;
        return head;
    }
};
