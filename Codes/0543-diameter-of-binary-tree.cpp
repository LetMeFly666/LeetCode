/*
 * @Author: LetMeFly
 * @Date: 2022-12-05 22:44:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-05 22:56:45
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
#ifdef FirstTry  // AC
class Solution {
private:
    int ans;

    int getDeepth(TreeNode* root) {
        if (!root)
            return 0;
        int left = getDeepth(root->left);
        int right = getDeepth(root->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        getDeepth(root);
        return ans - 1;
    }
};
#else  // FirstTry
// SecondTry  // 小改动
class Solution {
private:
    int ans;

    int getDeepth(TreeNode* root) {
        if (!root)
            return 0;
        int left = getDeepth(root->left);
        int right = getDeepth(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        getDeepth(root);
        return ans;
    }
};
#endif  // FirstTry