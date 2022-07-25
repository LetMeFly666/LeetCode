/*
 * @Author: LetMeFly
 * @Date: 2022-07-25 14:13:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-25 14:23:30
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
class CBTInserter {
private:
    vector<TreeNode*> a;
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* p = q.front();
            q.pop();
            a.push_back(p);
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
    
    int insert(int val) {
        TreeNode* thisNode = new TreeNode(val);
        a.push_back(thisNode);
        int th = a.size();
        TreeNode* father = a[th / 2 - 1];
        if (th % 2) {
            father->right = thisNode;
        }
        else {
            father->left = thisNode;
        }
        return father->val;
    }
    
    TreeNode* get_root() {
        return a[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */