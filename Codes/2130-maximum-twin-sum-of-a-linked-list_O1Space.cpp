/*
 * @Author: LetMeFly
 * @Date: 2026-06-14 21:49:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-14 22:48:35
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
1 2
  | |

1 2 3 4
  | |
    |   |
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast) {
            fast = fast->next->next;  // 因为链表是偶数个节点，所以fast->next一定非null
            slow = slow->next;
        }
        // cout << "next_half's begin: " << slow->val << endl;

        ListNode* last = slow;
        for (ListNode* now = last->next; now; ) {
            // if (!now) {
            //     cout << "what? now is nullptr" << endl;
            //     return -1;
            // }
            ListNode* next = now->next;
            now->next = last;
            last = now;
            now = next;
        }
        slow->next = nullptr;

        int ans = 0;
        ListNode* p1 = head, *p2 = last;
        while (p1 != slow) {
            ans = max(ans, p1->val + p2->val);
            p1 = p1->next, p2 = p2->next;
        }
        return ans;
    }
};

#ifdef _DEBUG
/*
[5,4,2,1]

6
*/
/*
[4,2,2,3]

7
*/
/*
[1,100000]

100001
*/
int main() {
    string s;
    while (cin >> s) {
        ListNode* head = stringToLinkedList(s);
        debug(head);
        Solution sol;
        cout << sol.pairSum(head) << endl;
        deleteLinkedList(head);  // 其实删不全，因为实际上有两个链表
    }
    return 0;
}
#endif
