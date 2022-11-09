/*
 * @Author: LetMeFly
 * @Date: 2022-09-08 16:21:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-08 16:23:16
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
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < a.size() / 2; i++) {
            if (a[i] != a[a.size() - i - 1])
                return false;
        }
        return true;
    }
};