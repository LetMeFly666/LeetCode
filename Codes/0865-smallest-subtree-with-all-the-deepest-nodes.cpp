/*
 * @Author: LetMeFly
 * @Date: 2026-01-09 13:11:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-09 13:13:17
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
    TreeNode* ans;
    
    int dfs(TreeNode* root) {
        int left = root->left ? dfs(root->left) : 0;
        int right = root->right ? dfs(root->right) : 0;
        if (left == right) {
            ans = root;
        }
        return max(left, right) + 1;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root);
        return ans;
    }
};