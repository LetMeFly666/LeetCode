/*
 * @Author: LetMeFly
 * @Date: 2026-06-14 21:48:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-14 21:48:39
 */
#ifdef _DEBUG
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
    int pairSum(ListNode* head) {
        int ans = 0;
        vector<int> vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        for (int l = 0, r = vals.size() - 1; l < r; l++, r--) {
            ans = max(ans, vals[l] + vals[r]);
        }
        return ans;
    }
};
