/*
 * @Author: LetMeFly
 * @Date: 2022-08-21 10:33:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-21 10:34:04
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
// From 2022-08-21 10:33:03 To 2022-08-21 10:34:04
// 1min 码完
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* lastNode = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = lastNode;
            lastNode = head;
            head = nextNode;
        }
        return lastNode;
    }
};