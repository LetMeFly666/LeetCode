/*
 * @Author: LetMeFly
 * @Date: 2022-06-19 09:41:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-19 09:44:55
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
    unordered_map<int, int> cnt;
    int M;

    int getValAndCount(TreeNode* root) {
        if (!root)
            return 0;
        int leftVal = getValAndCount(root->left);
        int rightVal = getValAndCount(root->right);
        int thisVal = root->val + leftVal + rightVal;
        cnt[thisVal]++;
        M = max(M, cnt[thisVal]);
        return thisVal;
    }
public:
    Solution() : M(0) {}

    vector<int> findFrequentTreeSum(TreeNode* root) {
        getValAndCount(root);
        vector<int> ans;
        for (auto[a, b] : cnt) {
            if (b == M) {
                ans.push_back(a);
            }
        }
        return ans;
    }
};