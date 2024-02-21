/*
 * @Author: LetMeFly
 * @Date: 2024-02-21 09:56:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-21 10:03:18
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

    TreeNode* dfs(vector<int>::iterator inLeft, vector<int>::iterator inRight, vector<int>::iterator postLeft, vector<int>::iterator postRight) {
        if (inLeft >= inRight) {
            return nullptr;
        }
        TreeNode* thisNode = new TreeNode(*(postRight - 1));
        vector<int>::iterator loc = ma[*(postRight - 1)];
        thisNode->left = dfs(inLeft, loc, postLeft, postLeft + (loc - inLeft));
        thisNode->right = dfs(loc + 1, inRight, postLeft + (loc - inLeft), postRight - 1);
        return thisNode;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); it++) {
            ma[*it] = it;
        }
        return dfs(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};