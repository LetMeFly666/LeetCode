/*
 * @Author: LetMeFly
 * @Date: 2024-02-20 10:54:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-20 11:10:37
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
private:
    unordered_map<int, vector<int>::iterator> ma;

    TreeNode* dfs(vector<int>::iterator preLeft, vector<int>::iterator preRight, vector<int>::iterator inLeft, vector<int>::iterator inRight) {
        if (preRight <= preLeft) {
            return nullptr;
        }
        TreeNode* thisNode = new TreeNode(*preLeft);
        vector<int>::iterator loc = ma[*preLeft];
        int leftLength = loc - inLeft;
        thisNode->left = dfs(preLeft + 1, preLeft + leftLength + 1, inLeft, loc);
        thisNode->right = dfs(preLeft + leftLength + 1, preRight, loc + 1, inRight);
        return thisNode;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); it++) {
            ma[*it] = it;
        }
        return dfs(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};