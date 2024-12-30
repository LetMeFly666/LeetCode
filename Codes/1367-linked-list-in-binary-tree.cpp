/*
 * @Author: LetMeFly
 * @Date: 2024-12-30 13:32:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-30 14:05:37
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
// class Solution {
// private:
//     bool dfs(ListNode* head, ListNode* now, TreeNode* root) {
//         if (!now) {
//             return true;
//         }
//         if (!root) {
//             return false;
//         }
//         if (now->val == root->val) {
//             if (dfs(head, now->next, root->left) || dfs(head, now->next, root->right)) {
//                 return true;
//             }
//         }
//         if (head != now) {
//             if (dfs(head, head, root)) {
//                 return true;
//             }
//         }
//         return dfs(head, now, root->left) || dfs(head, now, root->right);
//     }
// public:
//     bool isSubPath(ListNode* head, TreeNode* root) {
//         return dfs(head, head, root);
//     }
// };
class Solution {
private:
    bool dfs(ListNode* head, ListNode* l, TreeNode* t) {
        if (!l) {
            return true;
        }
        if (!t) {
            return false;
        }
        return l->val == t->val && (dfs(head, l->next, t->left) || dfs(head, l->next, t->right)) ||
               head == l && (dfs(head, l, t->left) || dfs(head, l, t->right));
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, head, root);
    }
};