/*
 * @Author: LetMeFly
 * @Date: 2024-04-05 11:59:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-05 12:02:17
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

    void dfs(TreeNode* root, int m, int M) {
        if (!root) {
            return;
        }
        ans =  max(ans, max(abs(root->val - m), abs(root->val - M)));
        m = min(m, root->val), M = max(M, root->val);
        dfs(root->left, m, M);
        dfs(root->right, m, M);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};