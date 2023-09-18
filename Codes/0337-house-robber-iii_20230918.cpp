/*
 * @Author: LetMeFly
 * @Date: 2023-09-18 08:17:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-18 08:24:50
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
    unordered_map<TreeNode*, int> robThis, notThis;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        robThis[root] = root->val + notThis[root->left] + notThis[root->right];
        notThis[root] = max(robThis[root->left], notThis[root->left]) + max(robThis[root->right], notThis[root->right]);
    }
public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(robThis[root], notThis[root]);
    }
};