/*
 * @Author: LetMeFly
 * @Date: 2022-01-16 08:53:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-01-16 08:55:09
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
    vector<int> vals;
public:
    Solution(ListNode* head) {
        vals.clear();
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */