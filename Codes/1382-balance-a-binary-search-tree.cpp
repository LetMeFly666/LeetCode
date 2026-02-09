/*
 * @Author: LetMeFly
 * @Date: 2026-02-09 23:05:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-09 23:21:12
 */
#if defined(_WIN32) || defined(__APPLE__)
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
/*
1 2 3 4 5 6 7 8 9

     5
  2     7
1  3   6 8
   4      9
*/
class Solution {
private:
    vector<TreeNode*> nodes;

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        nodes.push_back(node);
        dfs(node->right);
    }

    TreeNode* build(int l, int r) {
        if (l >= r) {
            return nullptr;
        }
        int mid = (l + r) >> 1;
        TreeNode* root = nodes[mid];
        root->left = build(l, mid);
        root->right = build(mid + 1, r);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return build(0, nodes.size());
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[1,null,2,null,3,null,4]
*/
int main() {
    string s;
    while (cin >> s) {
        TreeNode* root = stringToTree(s);
        cout << "original tree: " << root << endl;
        Solution sol;
        root = sol.balanceBST(root);
        deleteTree(root);
    }
    return 0;
}
#endif