/*
 * @Author: LetMeFly
 * @Date: 2022-07-11 11:40:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-11 11:42:27
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
    int minDeepth = INT_MAX;

    void dfs(TreeNode* root, int nowDeepth) {
        if (!root->left && !root->right)  // 叶节点
            minDeepth = min(minDeepth, nowDeepth);
        if (root->left)
            dfs(root->left, nowDeepth + 1);
        if (root->right)
            dfs(root->right, nowDeepth + 1);
    }
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root, 1);
        return minDeepth;
    }
};