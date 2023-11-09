/*
 * @Author: LetMeFly
 * @Date: 2023-11-03 00:13:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-03 00:28:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"

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

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            Node* last = nullptr;
            while (n--) {
                Node* thisNode = q.front();
                q.pop();
                if (last) {
                    last->next = thisNode;
                }
                if (thisNode->left) {
                    q.push(thisNode->left);
                }
                if (thisNode->right) {
                    q.push(thisNode->right);
                }
                last = thisNode;
            }
        }
        return root;
    }
};
// Not the best answer