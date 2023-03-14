/*
 * @Author: LetMeFly
 * @Date: 2023-03-14 21:37:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-14 21:41:03
 * @More: From郅非And Changed，帮郅非调BUG
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> a;
        queue<TreeNode*> b;
        TreeNode* t=root;
        while(t!=p&&t){
            a.push(t);
            if(p->val>t->val&&t->right) t=t->right;
            else if(p->val<t->val&&t->left) t=t->left;
        }
        a.push(t);
        t=root;
        while(t!=q&&t){
            b.push(t);
            if(q->val>t->val&&t->right) t=t->right;
            else if(q->val<t->val&&t->left) t=t->left;
        }
        b.push(t);
        TreeNode* ans;
        while(!a.empty()&&!b.empty()){
            if(a.front()==b.front()){
                ans=a.front();
                a.pop();
                b.pop();
            }
            else{
                break;
            }
        }
        return ans;
    }
};