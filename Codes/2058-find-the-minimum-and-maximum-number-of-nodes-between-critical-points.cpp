/*
 * @Author: LetMeFly
 * @Date: 2026-08-31 12:11:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-31 13:21:36
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
private:
    int lastIdx = -1;
    int mDis = -1;
    int MDis = -1;

    void updateDis(int idx) {
        if (lastIdx == -1) {
            lastIdx = idx;
            return;
        }
        int dis = idx - lastIdx;
        if (mDis == -1) {
            mDis = MDis = dis;
        } else {
            mDis = min(mDis, dis);
            MDis = max(MDis)
        }
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
    }
};
