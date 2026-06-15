/*
 * @Author: LetMeFly
 * @Date: 2026-06-15 17:02:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-15 17:17:32
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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt = 0;
        for (ListNode* p = head; p; cnt++, p = p->next) {}
        if (cnt == 1) {
            // delete head;  // cannot，否则力扣尝试删除head会报错
            return nullptr;
        }
        
        ListNode* p = head;
        for (int i = 1, target = cnt / 2; i < target; i++) {  // 7->4, 4->3
            p = p->next;
        }
        ListNode* to_remove = p->next;  // 一定非null
        p->next = to_remove->next;
        delete to_remove;
        return head;
    }
};

#ifdef _DEBUG
/*
[1,3,4,7,1,2,6]

[1,3,4,1,2,6]
*/

/*
[1]

[]
*/
int main() {
    string s;
    while (cin >> s) {
        ListNode* head = stringToLinkedList(s);
        Solution sol;
        ListNode* new_head = sol.deleteMiddle(head);
        debug(new_head);
        deleteLinkedList(new_head);
    }
    return 0;
}
#endif
