/*
 * @Author: LetMeFly
 * @Date: 2022-07-21 18:45:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-21 18:49:13
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
    /* 判断此节点的 左/右 子树是否为全0二叉树。若是，则移除对应子树 */
    bool isZero(TreeNode* root) {
        bool is0 = true;
        if (root->val)
            is0 = false;
        if (root->left) {
            if (isZero(root->left)) {
                root->left = nullptr;
            }
            else {
                is0 = false;
            }
        }
        if (root->right) {
            if (isZero(root->right)) {
                root->right = nullptr;
            }
            else {
                is0 = false;
            }
        }
        return is0;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (isZero(root))
            root = nullptr;
        return root;
    }
};