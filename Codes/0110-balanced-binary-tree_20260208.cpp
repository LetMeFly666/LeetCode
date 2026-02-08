/*
 * @Author: LetMeFly
 * @Date: 2026-02-08 13:40:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-08 13:42:19
 */
#if defined(_WIN32) || defined(__APPLE__)
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
    int ok;

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (abs(left - right) > 1) {
            ok = false;
        }
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        ok = true;
        dfs(root);
        return ok;
    }
};