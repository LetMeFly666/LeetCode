/*
 * @Author: LetMeFly
 * @Date: 2023-12-15 09:32:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-15 16:03:26
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
    void dfs(TreeNode* left, TreeNode* right, bool shouldReverse) {
        if (!left) {
            return ;
        }
        if (shouldReverse) {
            swap(left->val, right->val);
        }
        dfs(left->left, right->right, !shouldReverse);
        dfs(left->right, right->left, !shouldReverse);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }
};