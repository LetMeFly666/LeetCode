/*
 * @Author: LetMeFly
 * @Date: 2022-04-06 21:02:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-06 21:12:42
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* p = head;
        bool JinWei = false;
        while (l1 || l2) {
            ListNode* node = new ListNode(JinWei);
            if (l1) {
                node->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                node->val += l2->val;
                l2 = l2->next;
            }
            JinWei = node->val / 10;
            node->val %= 10;
            p->next = node;
            p = node;
        }
        if (JinWei) {
            p->next = new ListNode(1);
        }
        return head->next;
    }
};