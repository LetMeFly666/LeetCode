/*
 * @Author: LetMeFly
 * @Date: 2023-12-15 09:32:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-15 15:59:59
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
    // 若shouldReverse则交换其左右子
    void dfs(TreeNode* root, bool shouldReverse) {
        if (!root->left) {
            return;
        }
        if (shouldReverse) {
            swap(root->left->val, root->right->val);
        }
        dfs(root->left, !shouldReverse);
        dfs(root->right, !shouldReverse);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root, true);
        return root;
    }
};