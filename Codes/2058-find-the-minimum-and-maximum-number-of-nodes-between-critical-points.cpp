/*
 * @Author: LetMeFly
 * @Date: 2026-08-31 12:11:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-01 13:10:00
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
    int lastIdx = -1, firstIdx = -1;
    int mDis = -1;
    int MDis = -1;

    void updateDis(int idx) {
        // cout << idx << endl;
        if (lastIdx == -1) {
            firstIdx = lastIdx = idx;
            return;
        }
        int dis = idx - lastIdx;
        if (mDis == -1) {
            mDis = MDis = dis;
        } else {
            mDis = min(mDis, dis);
            MDis = idx - firstIdx;
        }
        lastIdx = idx;  // 看来思路还是不能断啊
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstVal = head->val;
        int secondVal = head->next->val;
        int idx = 0;
        for (head = head->next->next; head; head = head->next, idx++) {
            int nowVal = head->val;
            if (secondVal < firstVal && secondVal < nowVal || secondVal > firstVal && secondVal > nowVal) {
                updateDis(idx);
            }
            firstVal = secondVal;
            secondVal = nowVal;
        }
        return {mDis, MDis};
    }
};
