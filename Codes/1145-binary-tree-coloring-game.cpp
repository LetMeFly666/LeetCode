/*
 * @Author: LetMeFly
 * @Date: 2023-02-03 22:51:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-03 22:56:31
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
    TreeNode* nodeX;
    int x;

    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        if (root->val == x)
            nodeX = root;
        return dfs(root->left) + dfs(root->right) + 1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        this->x = x;
        dfs(root);  // 找到x
        int left = dfs(nodeX->left);
        int right = dfs(nodeX->right);
        return (left > n - left) || (right > n - right) || (n - left - right - 1 > left + right + 1);
    }
};