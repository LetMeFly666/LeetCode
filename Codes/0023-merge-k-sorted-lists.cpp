/*
 * @Author: LetMeFly
 * @Date: 2022-05-12 09:27:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-12 09:43:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " : " << x << endl
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
struct cmp {
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};
#define nDEBUG
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode;
        ListNode* p = head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (ListNode* thisHead : lists) {
            if (thisHead) {
                pq.push(thisHead);  // 啊，之前push成head了
            }
        }
        #ifdef DEBUG
        auto temp = pq;
        while (temp.size()) {
            dbg(temp.top()->val);
            temp.pop();
        }
        #endif
        while (pq.size()) {
            ListNode* thisNode = pq.top();
            pq.pop();
            #ifdef DEBUG
            dbg(thisNode->val);
            dbg(thisNode->next);
            dbg((thisNode->next == thisNode));
            #endif
            p->next = thisNode;
            p = p->next;
            if (thisNode->next) {
                pq.push(thisNode->next);
            }
        }
        return head->next;
    }
};