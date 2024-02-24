/*
 * @Author: LetMeFly
 * @Date: 2024-02-24 10:28:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-24 11:04:07
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
    vector<int> v;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        vector<vector<int>> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int m = -1, M = -1;
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), queries[i]);
            if (it != v.end()) {
                M = *it;
                if (M == queries[i]) {
                    m = M;
                    goto loop;
                }
            }
            if (it != v.begin()) {
                m = *(it - 1);
            }
            loop:
            ans[i] = {m, M};
        }
        return ans;
    }
};