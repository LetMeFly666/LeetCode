/*
 * @Author: LetMeFly
 * @Date: 2023-05-30 08:53:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-30 08:57:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<TreeNode*> ans;
    unordered_set<int> toDelete;

    bool dfs(TreeNode* root) {  // 是否需要保留root
        if (!root) {
            return false;
        }
        bool keepLeft = dfs(root->left);
        bool keepRight = dfs(root->right);
        if (toDelete.count(root->val)) {  // 删root
            if (keepLeft) {
                ans.push_back(root->left);
            }
            if (keepRight) {
                ans.push_back(root->right);
            }
            // delete root;
            return false;
        }
        else {
            root->left = keepLeft ? root->left : nullptr;
            root->right = keepRight ? root->right : nullptr;
            return true;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int t : to_delete) {
            toDelete.insert(t);
        }
        if (dfs(root)) {
            ans.push_back(root);
        }
        return ans;
    }
};