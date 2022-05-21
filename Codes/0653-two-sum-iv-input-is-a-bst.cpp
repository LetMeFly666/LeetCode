/*
 * @Author: LetMeFly
 * @Date: 2022-03-21 08:42:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-21 09:44:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
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
#ifdef FirstTry
// 忘记考虑了自己和自己不能相加。
class Solution {
private:
    set<int> se;
    void dfs(TreeNode* root) {
        if (!root)
            return ;
        se.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        for (set<int>::iterator it = se.begin(); it != se.end(); it++) {
            if (se.count(k - *it)) {
                return true;
            }
        }
        return false;
    }
};
#else
class Solution {
private:
    map<int, int> ma;
    void dfs(TreeNode* root) {
        if (!root)
            return ;
        // dbg(root->val); //********
        ma[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        // for (auto it = ma.begin(); it != ma.end(); it++) {
        //     dbg(it->first);
        // }
        for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++) {
            int val = it->first;
            // dbg(val);
            if (k - val == val) {
                if (ma[val] >= 2)
                    return true;
            }
            else {
                if (ma.count(k - val)) {
                    // dbg(val);  //**************
                    // dbg(ma[k - val]);  //*******
                    return true;
                }
            }
            
        }
        return false;
    }
};
#endif