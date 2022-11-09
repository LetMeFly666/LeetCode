/*
 * @Author: LetMeFly
 * @Date: 2022-10-14 10:43:28
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-14 10:47:47
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
        stack<int> st1, st2;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        stack<int> added;
        int carry = 0;
        while (st1.size() || st2.size()) {
            if (st1.size()) {
                carry += st1.top();
                st1.pop();
            }
            if (st2.size()) {
                carry += st2.top();
                st2.pop();
            }
            added.push(carry % 10);
            carry /= 10;
        }
        if (carry)
            added.push(carry);
        ListNode* ans = new ListNode;
        ListNode* p = ans;
        while (added.size()) {
            p->next = new ListNode(added.top());
            added.pop();
            p = p->next;
        }
        return ans->next;
    }
};