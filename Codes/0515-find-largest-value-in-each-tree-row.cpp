/*
 * @Author: LetMeFly
 * @Date: 2022-06-24 17:56:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-24 18:01:40
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

typedef pair<TreeNode*, int> pii;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        queue<pii> q;
        int lastLayer = 0;
        int M = INT_MIN;
        q.push({root, 0});
        while (q.size()) {
            pii thisP = q.front();
            q.pop();
            if (thisP.second != lastLayer) {
                lastLayer = thisP.second;
                ans.push_back(M);
                M = INT_MIN;
            }
            M = max(M, thisP.first->val);
            if (thisP.first->left)
                q.push({thisP.first->left, thisP.second + 1});
            if (thisP.first->right)
                q.push({thisP.first->right, thisP.second + 1});
        }
        ans.push_back(M);
        return ans;
    }
};