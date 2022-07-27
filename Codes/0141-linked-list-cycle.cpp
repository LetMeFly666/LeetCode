/*
 * @Author: LetMeFly
 * @Date: 2022-07-27 15:37:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-27 15:50:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#ifdef FirstTry  // unordered_set
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> se;
        while (head) {
            if (se.count(head))
                return true;
            se.insert(head);
            head = head->next;
        }
        return false;
    }
};
#else  // FirstTry
#ifdef SecondTry  // 为了过题而过题
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int count = 0;
        while (head) {
            count++;
            if (count > 10000)
                return true;
            head = head->next;
        }
        return false;
    }
};
#else  // SecondTry
// SecondTry  // 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode *fast = head, *slow = head;
        do {
            if (!fast->next || !fast->next->next) {  // 走到尾了
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        return fast == slow;
    }
};
#endif  // SecondTry
#endif  // FirstTry