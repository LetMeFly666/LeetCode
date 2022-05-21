/*
 * @Author: LetMeFly
 * @Date: 2021-07-28 10:43:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-28 11:23:43
 */



#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node
{
    int val;
    Node *f, *l, *r;
    bool visited;
};
typedef Node *PN;
TreeNode *toFind;
PN from;
PN build(TreeNode *oriThisNode, PN father)
{
    if(!oriThisNode)
        return NULL;
    PN thisNode=new Node;
    if(oriThisNode==toFind)
        from=thisNode;
    thisNode->f=father;
    thisNode->val=oriThisNode->val;
    thisNode->l=build(oriThisNode->left, thisNode);
    thisNode->r=build(oriThisNode->right, thisNode);
    thisNode->visited=false;
    return thisNode;
}
typedef pair<PN, int> pii; // PN, distance
class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        toFind=target;
        PN newRoot=build(root, NULL);
        vector<int>ans;
        queue<pii>q;
        from->visited=true;
        q.push(pii(from, 0));
        while(q.size())
        {
            pii thisP=q.front();
            q.pop();
            int distance=thisP.second;
            if(distance==k)ans.push_back(thisP.first->val);
            else if(distance>k)continue;
            PN pn[3]={thisP.first->f, thisP.first->l, thisP.first->r};
            for(int i=0;i<3;i++)
            {
                if(pn[i]&&!(pn[i]->visited))
                {
                    pn[i]->visited=true;
                    q.push(pii(pn[i],distance+1));
                }
            }
        }
        return ans;
    }
};