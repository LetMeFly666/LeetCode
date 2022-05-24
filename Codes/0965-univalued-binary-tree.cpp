/*
 * @Author: LetMeFly
 * @Date: 2022-05-24 08:52:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-24 08:54:13
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
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* p = q.front();
            q.pop();
            if (p->val != val)
                return false;
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        return true;
    }
};