/*
 * @Author: LetMeFly
 * @Date: 2024-02-13 11:03:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-13 11:10:24
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;  // [<node, col>, ...
        q.push({root, 0});
        vector<pair<TreeNode*, int>> v;
        while (q.size()) {
            pair<TreeNode*, int> thisNode = q.front();
            q.pop();
            v.push_back(thisNode);
            if (thisNode.first->left) {
                q.push({thisNode.first->left, thisNode.second - 1});
            }
            if (thisNode.first->right) {
                q.push({thisNode.first->right, thisNode.second + 1});
            }
        }
        sort(v.begin(), v.end(), [&](const pair<TreeNode*, int>& a, const pair<TreeNode*, int>& b) {
            return a.second == b.second ? a.first->val < b.first->val : a.second < b.second;
        });
        vector<vector<int>> ans;
        int lastLayer = 1000000;
        for (pair<TreeNode*, int>& a : v) {
            if (a.second != lastLayer) {
                lastLayer = a.second;
                ans.push_back({});
            }
            ans.back().push_back(a.first->val);
        }
        return ans;
    }
};