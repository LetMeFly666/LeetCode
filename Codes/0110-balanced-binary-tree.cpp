/*
 * @Author: LetMeFly
 * @Date: 2022-07-09 11:40:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-09 11:50:24
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
#ifdef FirstTry  // map记录
class Solution {
private:
    unordered_map<TreeNode*, int> ma;
    bool ok = true;

    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        if (ma.count(root))
            return ma[root];
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (abs(left - right) > 1) {
            ok = false;
        }
        return ma[root] = max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return ok;
    }
};
#else  // FirstTry
// SecondTry  // 不使用map记录（因为完全没有必要）
class Solution {
private:
    bool ok = true;

    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (abs(left - right) > 1) {
            ok = false;
        }
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return ok;
    }
};
#endif  // FirstTry