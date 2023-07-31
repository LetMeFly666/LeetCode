/*
 * @Author: LetMeFly
 * @Date: 2022-07-28 11:27:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-31 21:46:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
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
#ifdef FirstTry  // 方法一，数组,O(n),O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        while (head) {
            v.push_back(head);
            head = head->next;
        }
        int l = 0, r = v.size() - 1;
        head = v[0];
        while (l <= r) {
            head->next = v[l++];
            head = head->next;
            head->next = v[r--];
            head = head->next;
        }
        head->next = nullptr;
    }
};
#else  // FirstTry
// SecondTry  // 方法二，找中点 reverse 合并
class Solution {
private:
    ListNode* getMiddle(ListNode* head) {  // 奇数长度[0, 1, 2]返回1，偶数长度[0, 1]返回0
        ListNode* fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* next = head->next;
        head->next = nullptr;
        while (next) {
            ListNode* nextNext = next->next;
            next->next = head;
            head = next;
            next = nextNext;
        }
        return head;
    }

    void mergeList(ListNode* p1, ListNode* p2) {
        while (p1 && p2) {
            ListNode* p1next = p1->next;
            ListNode* p2next = p2->next;
            p1->next = p2, p2->next = p1next;
            p1 = p1next, p2 = p2next;
        }
    }
public:
    void reorderList(ListNode* head) {
        ListNode* middle4pre = getMiddle(head);
        // dbg(middle4pre->val);
        ListNode* middle = reverseList(middle4pre->next);
        // dbg(middle->val);
        // dbg(middle->next->val);
        // dbg(middle->next->next);
        middle4pre->next = nullptr;
        mergeList(head, middle);
    }
};
#endif  // FirstTry