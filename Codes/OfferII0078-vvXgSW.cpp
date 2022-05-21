/*
 * @Author: LetMeFly
 * @Date: 2022-04-13 15:53:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-13 15:57:13
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

using Point = ListNode*;

struct cmp {
    bool operator() (const Point& a, const Point& b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* p = head;
        priority_queue<Point, vector<Point>, cmp> q;
        for (Point& thisList : lists) {
            if (thisList)
                q.push(thisList);
        }
        while (q.size()) {
            Point thisPoint = q.top();
            q.pop();
            p->next = thisPoint;
            p = thisPoint;
            if (thisPoint->next) {
                q.push(thisPoint->next);
            }
        }
        return head->next;
    }
};