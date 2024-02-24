/*
 * @Author: LetMeFly
 * @Date: 2024-02-24 10:28:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-24 10:43:21
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
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* thisNode = q.front();
            q.pop();
            v.push_back(thisNode->val);
            if (thisNode->left) {
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                q.push(thisNode->right);
            }
        }
        vector<vector<int>> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            vector<int>::iterator upper = lower_bound(v.begin(), v.end(), queries[i]);

        }
    }
};