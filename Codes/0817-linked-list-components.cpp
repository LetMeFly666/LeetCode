/*
 * @Author: LetMeFly
 * @Date: 2022-10-12 10:38:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-12 10:38:46
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> se;
        for (int& t : nums) {
            se.insert(t);
        }
        int ans = 0;
        bool lastIsIn = false;
        while (head) {
            if (se.count(head->val) && !lastIsIn) {
                ans++;
            }
            lastIsIn = se.count(head->val);
            head = head->next;
        }
        return ans;
    }
};