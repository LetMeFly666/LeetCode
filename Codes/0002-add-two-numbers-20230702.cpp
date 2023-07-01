/*
 * @Author: LetMeFly
 * @Date: 2023-07-02 07:07:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-02 07:11:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode, *p = head;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(carry % 10);
            p = p->next;
            carry /= 10;
        }
        return head->next;
    }
};