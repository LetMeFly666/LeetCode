/*
 * @Author: LetMeFly
 * @Date: 2022-07-16 15:50:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-16 15:54:14
 */
#ifdef _WIN32
#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
#endif

typedef pair<Node*, int> pii;
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<pii> q;
        q.push({root, 1});
        int lastLayer = 0;
        Node* lastNode;
        while (q.size()) {
            auto[thisNode, thisLayer] = q.front();
            q.pop();
            if (thisLayer == lastLayer) {
                lastNode->next = thisNode;
            }
            lastNode = thisNode;
            lastLayer = thisLayer;
            if (thisNode->left)
                q.push({thisNode->left, thisLayer + 1});
            if (thisNode->right)
                q.push({thisNode->right, thisLayer + 1});
        }
        return root;
    }
};