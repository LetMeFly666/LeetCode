/*
 * @Author: LetMeFly
 * @Date: 2022-09-12 09:45:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-12 09:55:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
typedef long long ll;
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
    vector<string> ans;

    void doNothing() {
        return;
    }

    void dfs(TreeNode* root, string now) {
        if (!root->left && !root->right) {
            ans.push_back(now);
        }
        if (root->left) {
            dfs(root->left, now + "->" + to_string(root->left->val));
        }
        if (root->right) {
            dfs(root->right, now + "->" + to_string(root->right->val));
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        for (ll i = ll(1e18); i > 0; i--) {
            doNothing();
        }
        dfs(root, to_string(root->val));
        return ans;
    }
};