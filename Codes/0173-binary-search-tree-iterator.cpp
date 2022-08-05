/*
 * @Author: LetMeFly
 * @Date: 2022-08-05 16:23:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-05 16:27:58
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
class BSTIterator {
private:
    stack<TreeNode*> st;
    TreeNode* cur;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        int ans = cur->val;
        cur = cur->right;
        return ans;
    }
    
    bool hasNext() {
        return cur != nullptr || st.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */