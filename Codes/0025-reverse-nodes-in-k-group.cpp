/*
 * @Author: LetMeFly
 * @Date: 2022-05-13 14:16:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-13 14:51:06
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
#ifdef FirstTry
// 死循环
class Solution {
private:
    /* 判断p后面是否还有至少k个节点 */
    bool haveKNodes(ListNode* p, int k) {
        // assert(p);  // p不能为空
        int s = 0;
        while (p->next && s < k) {
            s++;
            p = p->next;            
        }
        return s >= k;
    }
public:
    ListNode* reverseKGroup(ListNode* head0, int k) {
        if (k == 1)
            return head0;
        ListNode* head = new ListNode(0, head0);
        ListNode* last = head;
        while (haveKNodes(last, k)) {
            ListNode* realLast = last;
            ListNode* first = last->next;

            ListNode* last = first;
            ListNode* thisNode = last->next;
            for (int i = 1; i < k; i++) {
                ListNode* next = thisNode->next;
                thisNode->next = last;
                last = thisNode;
                thisNode = next;
            }

            first->next = thisNode;
            realLast->next = last;
        }
        return head->next;
    }
};
#else
class Solution {
private:
    bool haveKNodes(ListNode* p, int k) {
        int s = 0;
        while (p->next && s < k) {
            s++;
            p = p->next;
        }
        return s >= k;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        ListNode* tempHead = new ListNode(0, head);

        ListNode* quanjvLast = tempHead;
        ListNode* quanjvFirst = quanjvLast->next;
        while (haveKNodes(quanjvLast, k)) {
            ListNode* first = quanjvLast->next;
            ListNode* second = first->next;
            for (int i = 1; i < k; i++) {
                ListNode* third = second->next;
                second->next = first;
                first = second;
                second = third;
            }
            quanjvLast->next = first;
            quanjvFirst->next = second;
            quanjvLast = quanjvFirst;
            quanjvFirst = quanjvLast->next;
        }

        return tempHead->next;
    }
};
#endif