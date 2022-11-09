/*
 * @Author: LetMeFly
 * @Date: 2022-07-30 12:02:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-30 12:09:24
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
// multimap,为了过题而过题
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        multimap<int, ListNode*> ma;
        while (head) {
            //不可以使用： ma[head->val] = head;
            ma.insert({head->val, head});
            head = head->next;
        }
        head = new ListNode;
        ListNode* lastNode = head;
        for (auto[val, node] : ma) {
            lastNode->next = node;
            lastNode = node;
        }
        lastNode->next = nullptr;  // 这个必须加上
        return head->next;
    }
};