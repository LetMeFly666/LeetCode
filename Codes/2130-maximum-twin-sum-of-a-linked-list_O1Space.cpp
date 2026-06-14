/*
 * @Author: LetMeFly
 * @Date: 2026-06-14 21:49:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-14 22:01:34
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
/*
_ 1 2
  | |

_ 1 2 3 4
  | |
    |   |
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* tmp = new ListNode(0, head);
        ListNode* slow = tmp, *fast = tmp;
        while (fast->next) {
            fast = fast->next->next;  // 因为链表是偶数个节点，所以有next一定会有next->next
            slow = slow->next;
        }

        ListNode* p = tmp;
        do {
            ListNode* next = p->next;
            next->next
        } while (p != slow);

        int ans = 0;

        return ans;
    }
};
