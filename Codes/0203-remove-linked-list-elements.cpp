/*
 * @Author: LetMeFly
 * @Date: 2022-08-19 08:38:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-19 08:44:52
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ansHead = new ListNode;
        ansHead->next = head;
        ListNode* last = ansHead, *current = ansHead->next;
        while (current) {
            if (current->val == val) {
                last->next = current->next;
                // delete current;  // Here should delete actually
                current = current->next;
            }
            else {
                last = current;
                current = current->next;
            }
        }
        // ListNode* head = ansHead;
        // delete head;
        return ansHead->next;
    }
};