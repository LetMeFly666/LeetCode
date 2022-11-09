/*
 * @Author: LetMeFly
 * @Date: 2022-07-09 11:14:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-09 11:27:54
 */
#ifdef _WIN32
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> ma;

    TreeNode* build(int l, int r) {  // [l, r)
        if (l >= r)
            return nullptr;
        int mid = (l + r) >> 1;
        TreeNode* root = new TreeNode(ma[mid]);
        root->left = build(l, mid);
        root->right = build(mid + 1, r);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int th = 0;
        while (head) {
            ma[th++] = head->val;
            head = head->next;
        }
        return build(0, th);
    }
};