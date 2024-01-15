/*
 * @Author: LetMeFly
 * @Date: 2024-01-15 21:33:23
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-15 21:38:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode(1000, head);
        ListNode* lastNode = ans, *thisNode = head;
        while (thisNode && thisNode->next) {
            if (thisNode->val == thisNode->next->val) {
                ListNode* nextNode = thisNode->next->next;
                while (nextNode && thisNode->val == nextNode->val) {
                    nextNode = nextNode->next;
                }
                lastNode->next = nextNode;
                lastNode = thisNode, thisNode = nextNode;
            }
            else {
                lastNode = thisNode, thisNode = thisNode->next;
            }
        }
        return ans->next;
    }
};