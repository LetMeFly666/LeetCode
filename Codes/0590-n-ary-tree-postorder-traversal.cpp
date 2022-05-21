/*
 * @Author: LetMeFly
 * @Date: 2022-03-12 15:57:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-12 15:58:52
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
        if (!root) 
            return ;
        for (Node* n : root->children)
            dfs(n);
        ans.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        dfs(root);
        return ans;
    }
};