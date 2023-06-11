/*
 * @Author: LetMeFly
 * @Date: 2023-06-11 14:32:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-11 14:51:40
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
#ifdef FirstTry  // Error
/*
[1,3,2,-3,-2,5,5,-5,1]

head->val = 1, cnt = 1
head->val = 3, cnt = 4
head->val = 2, cnt = 6
head->val = -3, cnt = 3
head->val = -2, cnt = 1
head->val = 5, cnt = 6
head->val = 5, cnt = 11
head->val = -5, cnt = 6
head->val = 1, cnt = 7

[2]->next = [-5]，但是[2]删了
*/
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* emptyHead = new ListNode;
        emptyHead->next = head;
        unordered_map<int, ListNode*> ma;
        ma[0] = emptyHead;
        int cnt = 0;
        while (head) {
            cnt += head->val;
            if (ma.count(cnt)) {
                ma[cnt]->next = head->next;
            }
            else {
                ma[cnt] = head;
            }
            printf("head->val = %d, cnt = %d\n", head->val, cnt);  //********
            head = head->next;
        }
        return emptyHead->next;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* emptyHead = new ListNode(0, head);
        unordered_map<int, ListNode*> lastAppear;
        int cnt = 0;
        for (ListNode* node = emptyHead; node; node = node->next) {
            cnt += node->val;
            lastAppear[cnt] = node;
        }
        cnt = 0;
        for (ListNode* node = emptyHead; node; node = node->next) {
            cnt += node->val;
            node->next = lastAppear[cnt]->next;
        }
        return emptyHead->next;
    }
};
#endif  // FirstTry