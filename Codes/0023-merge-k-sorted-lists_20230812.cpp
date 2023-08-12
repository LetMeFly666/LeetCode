/*
 * @Author: LetMeFly
 * @Date: 2023-08-12 08:10:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-12 08:25:39
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
private:
    struct cmp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (ListNode*& node : lists) {
            if (node) {
                pq.push(node);
            }
        }
        ListNode* head = new ListNode(), *p = head;
        while (pq.size()) {
            ListNode* thisNode = pq.top();
            pq.pop();
            p->next = thisNode;
            p = thisNode;
            if (thisNode->next) {
                pq.push(thisNode->next);
            }
        }
        return head->next;
    }
};