/*
 * @Author: LetMeFly
 * @Date: 2026-09-10 14:33:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-10 14:36:39
 */
#ifdef _DEBUG
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
typedef pair<int, int> pii;
class Solution {
private:
    int ans;

    pii dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        auto [vl, nl] = dfs(root->left);
        auto [vr, nr] = dfs(root->right);
        int val = root->val + vl + vr;
        int n = 1 + nl + nr;
        ans += root->val == val / n;
        return {val, n};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
