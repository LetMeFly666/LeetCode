/*
 * @Author: LetMeFly
 * @Date: 2024-02-13 11:03:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-13 11:16:19
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
typedef pair<TreeNode*, pair<int, int>> NodeInfo;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<NodeInfo> q;  // [<node, <col, height>>, ...
        q.push({root, {0, 1}});
        vector<NodeInfo> v;
        while (q.size()) {
            NodeInfo thisNode = q.front();
            q.pop();
            v.push_back(thisNode);
            if (thisNode.first->left) {
                q.push({thisNode.first->left, {thisNode.second.first - 1, thisNode.second.second + 1}});
            }
            if (thisNode.first->right) {
                q.push({thisNode.first->right, {thisNode.second.first + 1, thisNode.second.second + 1}});
            }
        }
        sort(v.begin(), v.end(), [&](const NodeInfo& a, const NodeInfo& b) {
            // if (a.second.first != b.second.first) {  // not same col
            //     return a.second.first < b.second.first;
            // }
            // if (a.second.second != b.second.second) {  // same col, different row
            //     return a.second.second < b.second.second;
            // }
            // return a.first->val < b.first->val;
            return a.second == b.second ? a.first->val < b.first->val : a.second < b.second;
        });
        vector<vector<int>> ans;
        int lastCol = 1000000;
        for (NodeInfo& a : v) {
            if (a.second.first != lastCol) {
                lastCol = a.second.first;
                ans.push_back({});
            }
            ans.back().push_back(a.first->val);
        }
        return ans;
    }
};