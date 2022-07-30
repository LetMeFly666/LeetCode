/*
 * @Author: LetMeFly
 * @Date: 2022-07-30 12:07:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-30 12:09:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// multimap,为了过题而过题
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        multimap<int, ListNode*> ma;
        while (head) {
            //不可以使用： ma[head->val] = head;
            ma.insert({head->val, head});
            head = head->next;
        }
        head = new ListNode;
        ListNode* lastNode = head;
        for (auto[val, node] : ma) {
            lastNode->next = node;
            lastNode = node;
        }
        lastNode->next = nullptr;  // 这个必须加上
        return head->next;
    }
};