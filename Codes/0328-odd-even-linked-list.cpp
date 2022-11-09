/*
 * @Author: LetMeFly
 * @Date: 2022-09-24 08:22:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-24 08:27:25
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode;
        ListNode* even = new ListNode;
        ListNode* pOdd = odd, *pEven = even;
        int cnt = 0;
        while (head) {
            if (cnt % 2) {
                pEven->next = head;
                pEven = head;
            }
            else {
                pOdd->next = head;
                pOdd = head;
            }
            head = head->next;
            cnt++;            
        }
        pOdd->next = even->next;
        pEven->next = nullptr;
        return odd->next;
    }
};