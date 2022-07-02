/*
 * @Author: LetMeFly
 * @Date: 2022-07-02 17:47:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-02 17:51:33
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
#ifdef FirstTry
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if ((p && !q) || (!p && q))
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
#else  // FirstTry
// SecondTry  // 代码简化版
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p) return !q;
        return q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
#endif  // FirstTry