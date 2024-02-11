/*
 * @Author: LetMeFly
 * @Date: 2024-02-11 10:48:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-11 10:49:51
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
class Solution {  // 这次写的和2022-07-29的除了一个中括号一模一样hh
private:
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};