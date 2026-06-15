/*
 * @Author: LetMeFly
 * @Date: 2026-06-15 17:02:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-15 17:09:44
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
        int cnt = 0;
        for (ListNode* p = head; p; cnt++, p = p->next) {}
        if (cnt == 1) {
            delete head;
            return nullptr;
        }
        
        ListNode* p = head;
        for (int i = 1, target = cnt / 2; i < target; i++) {  // 7->4, 4->3
            p = p->next;
        }
        ListNode* to_remove = p->next;  // 一定非null
        p->next = to_remove->next;
        delete to_remove;
        return head;
    }
};
