/*
 * @Author: LetMeFly
 * @Date: 2026-01-07 21:29:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-07 21:42:23
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
    int dfs(TreeNode* root, int cnt = 0) {
        int leftSum = 0, rightSum = 0;
        cnt += root->val;
        if (root->left) {
            leftSum = dfs(root->left, cnt);
        }
        if (root->right) {
            rightSum = dfs(root->right, cnt);
        }
        ans = max(ans, (cnt + leftSum) * rightSum);
        ans = max(ans, (cnt + rightSum) * leftSum);
        // printf("root->val = %d, cnt = %d, leftSum = %d, rightSum = %d\n", root->val, cnt, leftSum, rightSum);
        return root->val + leftSum + rightSum;
    }
public:
    int maxProduct(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};