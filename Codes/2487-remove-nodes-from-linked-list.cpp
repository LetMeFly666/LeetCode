/*
 * @Author: LetMeFly
 * @Date: 2024-01-03 10:23:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-03 10:26:31
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        while (head) {
            while (st.size() && st.top()->val < head->val) {
                st.pop();
            }
            st.push(head);
            head = head->next;
        }
        ListNode* lastNode = nullptr;
        while (st.size()) {
            ListNode* thisNode = st.top();
            st.pop();
            thisNode->next = lastNode;
            lastNode = thisNode;
        }
        return lastNode;
    }
};