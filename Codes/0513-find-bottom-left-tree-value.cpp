/*
 * @Author: LetMeFly
 * @Date: 2022-06-22 08:47:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-22 08:50:58
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
    int findBottomLeftValue(TreeNode* root) {
        int lastLayer = -1;
        int lastFirstVal;
        queue<pii> q;
        q.push({root, 0});
        while (q.size()) {
            pii thisP = q.front();
            q.pop();
            if (thisP.second != lastLayer) {
                lastLayer = thisP.second;
                lastFirstVal = thisP.first->val;
            }
            if (thisP.first->left) {
                q.push({thisP.first->left, thisP.second + 1});
            }
            if (thisP.first->right) {
                q.push({thisP.first->right, thisP.second + 1});
            }
        }
        return lastFirstVal;
    }
};