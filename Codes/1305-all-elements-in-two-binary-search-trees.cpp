/*
 * @Author: LetMeFly
 * @Date: 2022-05-01 11:41:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-01 11:49:38
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

void dfs(TreeNode* root, vector<int>& v) {
    if (!root)
        return;
    dfs(root->left, v);
    v.push_back(root->val);
    dfs(root->right, v);
}

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> n1, n2, ans;
        dfs(root1, n1);
        dfs(root2, n2);
        vector<int>::iterator p1 = n1.begin(), p2 = n2.begin();
        while (true) {
            if (p1 == n1.end()) {
                ans.insert(ans.end(), p2, n2.end());
                break;
            }
            if (p2 == n2.end()) {
                ans.insert(ans.end(), p1, n1.end());
                break;
            }
            if (*p1 < *p2) {
                ans.push_back(*p1++);
            }
            else {
                ans.push_back(*p2++);
            }
        }
        return ans;
    }
};