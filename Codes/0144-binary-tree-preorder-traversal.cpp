/*
 * @Author: LetMeFly
 * @Date: 2022-07-29 15:39:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-29 15:40:31
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
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (!root)
            return;
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