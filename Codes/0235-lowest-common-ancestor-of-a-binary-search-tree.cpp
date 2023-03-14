/*
 * @Author: LetMeFly
 * @Date: 2023-03-14 21:37:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-14 21:39:59
 * @More: From郅非，帮郅非调BUG
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
void debug(queue<TreeNode*> a, string name) {
    cout << name << ":";
    while (a.size()) {
        cout << " " << a.front()->val;
        a.pop();
    }
    cout << endl;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> a;
        queue<TreeNode*> b;
        TreeNode* t=root;
        while(t!=p&&t){
            printf("t->val = %d\n", t->val);  //******
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
        debug(a, "a");
        debug(b, "b");
        TreeNode* ans;
        while(!a.empty()&&!b.empty()){
            printf("a.front()->val = %d, b.front()->val = %d\n", a.front()->val, b.front()->val);
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