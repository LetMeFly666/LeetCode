/*
 * @Author: LetMeFly
 * @Date: 2022-05-30 10:46:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-30 10:50:08
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
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {  // 不会为空
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* p = q.front();
            q.pop();
            if (p->left || p->right) {
                if (p->left) {
                    p->left->val += (p->val) << 1;
                    q.push(p->left);
                }
                if (p->right) {
                    p->right->val += (p->val) << 1;
                    q.push(p->right);
                }
            }
            else {
                ans += p->val;
            }
        }
        return ans;
    }
};