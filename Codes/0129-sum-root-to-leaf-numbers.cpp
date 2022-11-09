/*
 * @Author: LetMeFly
 * @Date: 2022-07-22 11:04:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-22 11:13:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

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
#ifdef FirstTry  // 看错题了
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);  // root不会为空
        while (q.size()) {
            TreeNode* p = q.front();
            q.pop();
            ans += p->val;
            if (p->left) {
                p->left->val += p->val;
                q.push(p->left);
            }
            if (p->right) {
                p->right->val += p->val;
                q.push(p->right);
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);  // root 非空
        while (q.size()) {
            TreeNode* p = q.front();
            q.pop();
            if (!p->left && !p->right) {
                ans += p->val;
                continue;
            }
            p->val *= 10;
            if (p->left) {
                p->left->val += p->val;
                q.push(p->left);
            }
            if (p->right) {
                p->right->val += p->val;
                q.push(p->right);
            }
        }
        return ans;
    }
};
#endif  // FirstTry