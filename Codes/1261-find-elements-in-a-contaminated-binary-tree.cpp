/*
 * @Author: LetMeFly
 * @Date: 2024-03-12 09:10:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-12 09:25:10
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
class FindElements {
private:
    unordered_set<int> se;

    void dfs(TreeNode* root, int val) {
        if (!root) {
            return;
        }
        root->val = val;
        se.insert(val);
        dfs(root->left, val * 2 + 1);
        dfs(root->right, val * 2 + 2);
    }
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return se.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */