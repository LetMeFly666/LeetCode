/*
 * @Author: LetMeFly
 * @Date: 2024-02-19 12:28:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-19 12:29:23
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
        for (Node* nextNode : root->children) {
            dfs(nextNode);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        if (root) {
            dfs(root);
        }
        return ans;
    }
};