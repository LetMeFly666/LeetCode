/*
 * @Author: LetMeFly
 * @Date: 2023-08-05 07:50:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-05 07:52:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// AC [2022-04-15 09:48:10 - 2022-04-15 09:50:42]
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* p = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                // list2->=next;
                list2 = list2->next;
            }
            p = p->next;
        }
        if (list1) {
            p->next = list1;
        }
        else {
            p->next = list2;
        }
        return head->next;
    }
};