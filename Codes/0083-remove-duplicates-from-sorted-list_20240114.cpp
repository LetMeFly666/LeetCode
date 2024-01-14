/*
 * @Author: LetMeFly
 * @Date: 2024-01-14 11:06:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-14 11:08:01
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode(1000, head);
        head = ans;
        while (head && head->next) {
            if (head->val == head->next->val) {
                head->next = head->next->next;  // haven't delete node
            }
            head = head->next;
        }
        return ans->next;
    }
};