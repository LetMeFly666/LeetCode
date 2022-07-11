/*
 * @Author: LetMeFly
 * @Date: 2022-07-11 12:02:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-11 12:04:35
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (q.size()) {
            TreeNode* thisNode = q.front();
            q.pop();
            if (thisNode->val == targetSum && (!thisNode->left) && (!thisNode->right))
                return true;
            if (thisNode->left) {
                thisNode->left->val += thisNode->val;
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                thisNode->right->val += thisNode->val;
                q.push(thisNode->right);
            }
        }
        return false;
    }
};