/*
 * @Author: LetMeFly
 * @Date: 2022-12-04 12:48:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-04 16:40:24
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
    int total;

    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->right);
        total = root->val = total + root->val;
        dfs(root->left);
    }
public:
    Solution() {total = 0;}

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};