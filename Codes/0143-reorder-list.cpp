/*
 * @Author: LetMeFly
 * @Date: 2022-07-28 11:27:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-28 11:31:25
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
    void reorderList(ListNode* head) {
        unordered_map<int, ListNode*> ma;
        int cnt = 0;
        while (head) {
            ma[cnt++] = head;
            head = head->next;
        }
        head = ma[0];
        int l = 1, r = cnt - 1;  // 待指定
        bool front = false;
        while (l <= r) {
            if (front) {
                head->next = ma[l++];
                front = false;
            }
            else {
                head->next = ma[r--];
                front = true;
            }
            head = head->next;
        }
        head->next = nullptr;
    }
};