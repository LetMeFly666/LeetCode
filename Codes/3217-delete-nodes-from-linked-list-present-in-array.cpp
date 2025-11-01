/*
 * @Author: LetMeFly
 * @Date: 2025-11-01 21:45:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-11-01 21:54:03
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif
// THIS IS NOT RIGHT
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
    ListNode* modifiedList(vector<int>& nums, ListNode* now) {
        unordered_set<int> se;
        ListNode* head(0, now);
        ListNode* last = head;
        while (now) {
            if (se.count(now->val)) {
                now = now->next;
                last->next = now;
            } else {
                last = now;
                now = now->next;
            }
        }
        return head->next;
    }
};