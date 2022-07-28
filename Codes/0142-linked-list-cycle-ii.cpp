/*
 * @Author: LetMeFly
 * @Date: 2022-07-28 11:00:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-28 11:01:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> se;
        while (head) {
            if (se.count(head))
                return head;
            se.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};