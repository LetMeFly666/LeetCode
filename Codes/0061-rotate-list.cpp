/*
 * @Author: LetMeFly
 * @Date: 2022-06-05 11:25:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-05 11:41:23
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int n = 0;
        ListNode* p = head;
        ListNode* end = nullptr;
        while (p) {
            end = p;
            n++;
            p = p->next;
        }
        // dbg(n);
        int moveNum = k % n;
        if (!moveNum)
            return head;
        int th = n - moveNum + 1;
        int nowTh = 2;
        // dbg(th);
        p = head;  // 上一个节点
        while (nowTh < th) {
            nowTh++;
            p = p->next;
            // dbg(p->val);
        }
        ListNode* newHead = p->next;
        p->next = nullptr;
        end->next = head;
        return newHead;
    }
};

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        
    }
    return 0;
}
#endif