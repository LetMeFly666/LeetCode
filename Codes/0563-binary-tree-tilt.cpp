/*
 * @Author: LetMeFly
 * @Date: 2021-11-18 13:17:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-18 13:23:28
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int ans;
    int getSumAndSum2Ans(TreeNode* root) {
        if (!root) return 0;
        int left = getSumAndSum2Ans(root->left);
        int right = getSumAndSum2Ans(root->right);
        ans += abs(left - right);
        return left + right + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        ans = 0;
        getSumAndSum2Ans(root);
        return ans;
    }
};