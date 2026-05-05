/*
 * @Author: LetMeFly
 * @Date: 2026-05-05 11:42:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-05 11:49:41
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        
        int n = 1;
        ListNode* p = head;
        while (p->next) {
            n++;
            p = p->next;
        }
        p->next = head;
        k %= n;
        k = n - k;

        p = head;
        for (int i = 1; i < k; i++) {
            p = p->next;
        }
        ListNode* ans = p->next;
        p->next = nullptr;
        return ans;
    }
};
