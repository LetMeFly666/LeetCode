/*
 * @Author: LetMeFly
 * @Date: 2023-04-18 12:01:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-18 12:04:52
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
    int ans = 0;

    void dfs(TreeNode* root, int M, int m) {
        if (!root) {
            return;
        }
        ans = max(ans, abs(root->val - M));
        ans = max(ans, abs(root->val - m));
        M = max(M, root->val);
        m = min(m, root->val);
        dfs(root->left, M, m);
        dfs(root->right, M, m);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};