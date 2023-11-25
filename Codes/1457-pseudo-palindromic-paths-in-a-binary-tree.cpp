/*
 * @Author: LetMeFly
 * @Date: 2023-11-25 17:34:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-25 17:37:10
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
    int ans;
    void dfs(TreeNode* root, int mask) {
        mask ^= (1 << root->val);
        if (!root->left && !root->right) {
            ans += __builtin_popcount(mask) < 2;
        }
        if (root->left) {
            dfs(root->left, mask);
        }
        if (root->right) {
            dfs(root->right, mask);
        }
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};