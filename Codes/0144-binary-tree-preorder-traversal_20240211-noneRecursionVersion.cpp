/*
 * @Author: LetMeFly
 * @Date: 2024-02-11 10:53:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-11 10:54:14
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while (st.size()) {
            TreeNode* thisNode = st.top();
            st.pop();
            if (!thisNode) {
                continue;
            }
            ans.push_back(thisNode->val);
            st.push(thisNode->right);
            st.push(thisNode->left);
        }
        return ans;
    }
};