/*
 * @Author: LetMeFly
 * @Date: 2022-06-26 10:24:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-26 10:29:55
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* le = new ListNode, *ge = new ListNode;
        ListNode* p1 = le, *p2 = ge;
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            }
            else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p1->next = ge->next;
        p2->next = nullptr;
        return le->next;
    }
};