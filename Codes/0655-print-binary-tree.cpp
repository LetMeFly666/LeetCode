/*
 * @Author: LetMeFly
 * @Date: 2022-08-22 10:02:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-22 10:15:05
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
struct Node {
    TreeNode* treeNode;
    int x, y;
    Node(TreeNode* treeNode, int x, int y) : treeNode(treeNode), x(x), y(y) {
        
    }
};

class Solution {
private:
    int getTreeHeight(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getTreeHeight(root);  // 这里的height就是题目中的height + 1
        vector<vector<string>> ans(height, vector<string>((1 << height) - 1));
        queue<Node> q;
        q.push({root, 0, ((1 << height) - 1) / 2});
        while (q.size()) {
            auto[node, x, y] = q.front();
            q.pop();
            ans[x][y] = to_string(node->val);
            if (node->left) {
                q.push({node->left, x + 1, y - (1 << (height - x - 2))});
            }
            if (node->right) {
                q.push({node->right, x + 1, y + (1 << (height - x - 2))});
            }
        }
        return ans;
    }
};