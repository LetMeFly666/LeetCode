/*
 * @Author: LetMeFly
 * @Date: 2026-02-24 21:34:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-24 21:37:38
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
    int ans;

    // @input.root not empty
    void dfs(TreeNode* root, int now) {
        now <<= 1;
        now += root->val;
        if (!root->left && !root->right) {
            ans += now;
            return;
        }
        if (root->left) {
            dfs(root->left, now);
        }
        if (root->right) {
            dfs(root->right, now);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};
