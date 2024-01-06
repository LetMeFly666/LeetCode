/*
 * @Author: LetMeFly
 * @Date: 2024-01-06 11:36:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-06 11:40:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = head;
        while (head && head->next) {
            ListNode* middle = new ListNode(__gcd(head->val, head->next->val));
            middle->next = head->next;
            head->next = middle;
            head = middle->next;
        }
        return ans;
    }
};