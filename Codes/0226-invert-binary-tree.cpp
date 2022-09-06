/*
 * @Author: LetMeFly
 * @Date: 2022-09-06 13:08:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-06 13:09:12
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* thisNode = q.front();
            q.pop();
            TreeNode* left = thisNode->left;
            TreeNode* right = thisNode->right;
            thisNode->left = right, thisNode->right = left;
            if (left)
                q.push(left);
            if (right)
                q.push(right);
        }
        return root;
    }
};