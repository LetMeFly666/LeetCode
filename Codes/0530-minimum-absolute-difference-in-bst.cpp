/*
 * @Author: LetMeFly
 * @Date: 2022-11-23 11:32:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-23 11:35:32
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
    int lastNum = -1e7;
    int ans = 1e7;

    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        // printf("root->val = %d, lastNum = %d\n", root->val, lastNum);  //********
        ans = min(ans, root->val - lastNum);
        lastNum = root->val;
        dfs(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};