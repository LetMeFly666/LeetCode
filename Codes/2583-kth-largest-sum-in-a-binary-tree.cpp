/*
 * @Author: LetMeFly
 * @Date: 2024-02-23 10:22:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-23 10:25:42
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
typedef long long ll;
class Solution {
public:
    ll kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> values;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            ll cnt = 0;
            for (int _ = q.size(); _ > 0; _--) {
                TreeNode* thisNode = q.front();
                q.pop();
                cnt += thisNode->val;
                if (thisNode->left) {
                    q.push(thisNode->left);
                }
                if (thisNode->right) {
                    q.push(thisNode->right);
                }
            }
            values.push_back(cnt);
        }
        sort(values.begin(), values.end());
        return k > values.size() ? -1 : values[values.size() - k];
    }
};