/*
 * @Author: LetMeFly
 * @Date: 2023-12-04 09:34:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-04 09:36:42
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
private:
    int last;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->right);
        last += root->val;
        root->val = last;
        dfs(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        last = 0;
        dfs(root);
        return root;
    }
};