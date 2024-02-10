/*
 * @Author: LetMeFly
 * @Date: 2024-02-10 11:17:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-10 11:28:23
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, bool>> st;  // [<node, ifPushedChild>, ...
        st.push({root, false});
        while (st.size()) {
            auto [thisNode, ifPushedChild] = st.top();
            st.pop();
            if (!thisNode) {
                continue;
            }
            if (ifPushedChild) {
                ans.push_back(thisNode->val);
            }
            else {
                st.push({thisNode->right, false});
                st.push({thisNode, true});
                st.push({thisNode->left, false});
            }
        }
        return ans;
    }
};