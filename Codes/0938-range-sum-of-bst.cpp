/*
 * @Author: LetMeFly
 * @Date: 2024-02-26 18:56:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-26 18:59:11
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
class Solution {  // AC,96.46%,73.98%
private:
    int ans;

    void dfs(TreeNode* root, int l, int r) {
        if (!root) {
            return;
        }
        dfs(root->left, l, r);
        if (root->val >= l && root->val <= r) {
            ans += root->val;
        }
        dfs(root->right, l, r);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans = 0;
        dfs(root, low, high);
        return ans;
    }
};