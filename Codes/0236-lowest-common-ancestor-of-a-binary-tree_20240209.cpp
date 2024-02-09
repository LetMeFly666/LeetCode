/*
 * @Author: LetMeFly
 * @Date: 2024-02-09 12:05:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-09 12:29:59
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef int Status;  // 一个二进制位表示子树中是否有节点p和节点q
#define NONE 0
#define ONLYP 1
#define ONLYQ 2
#define BOTH 3

class Solution {
private:
    TreeNode* ans;

    Status dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NONE;
        }
        Status thisStatus = NONE;
        if (root == p) {
            thisStatus |= ONLYP;
        }
        if (root == q) {
            thisStatus |= ONLYQ;
        }
        thisStatus |= dfs(root->left, p, q) | dfs(root->right, p, q);
        if (thisStatus == BOTH && !ans) {
            ans = root;
        }
        return thisStatus;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        dfs(root, p, q);
        return ans;
    }
};