/*
 * @Author: LetMeFly
 * @Date: 2026-01-07 21:29:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-07 21:52:59
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
typedef long long ll;
class Solution {
private:
    vector<int> subTreeSum;
    int dfs(TreeNode* root) {
        int leftSum = 0, rightSum = 0;
        if (root->left) {
            leftSum = dfs(root->left);
            subTreeSum.push_back(leftSum);
        }
        if (root->right) {
            rightSum = dfs(root->right);
            subTreeSum.push_back(rightSum);
        }
        return root->val + leftSum + rightSum;
    }
public:
    int maxProduct(TreeNode* root) {
        int totalSum = dfs(root);
        ll ans = 0;
        for (int t : subTreeSum) {
            ans = max(ans, (ll)t * (totalSum - t));
        }
        return ans % 1000000007;
    }
};