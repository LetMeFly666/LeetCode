/*
 * @Author: LetMeFly
 * @Date: 2025-03-03 18:17:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-03 21:01:10
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
typedef unsigned long long ull;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ull ans = 1;
        queue<pair<TreeNode*, ull>> q;
        q.push({root, 0});
        while (q.size()) {
            cout << q.size() << endl;
            ull m = -1, M = 0;  // 0是最小值，-1是最大值（2^{64}-1）
            for (int i = q.size(); i > 0; i--) {
                auto [node, num] = q.front();
                cout << node->val << ',' << num << endl;
                q.pop();
                m = min(m, num);
                M = max(M, num);
                if (node->left) {
                    q.push({node->left, num * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, num * 2 + 2});
                }
            }
            // printf("ans = max(%lld, %lld) = %lld\n", ans, M - m + 1, max(ans, M - m + 1));
            ans = max(ans, M - m + 1);
        }
        return ans;
    }
};