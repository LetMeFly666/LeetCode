/*
 * @Author: LetMeFly
 * @Date: 2024-02-18 11:56:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-18 11:57:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> ans;

    void dfs(Node* root) {
        if (!root) {
            return;
        }
        ans.push_back(root->val);
        for (Node* nextNode : root->children) {
            dfs(nextNode);
        }
    }
public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};