/*
 * @Author: LetMeFly
 * @Date: 2024-02-17 10:48:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-17 10:51:47
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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if (root) {
            q.push(root);
        }
        while (q.size()) {
            ans.push_back({});
            for (int _ = q.size(); _ > 0; _--) {
                Node* thisNode = q.front();
                q.pop();
                ans.back().push_back(thisNode->val);
                for (Node* nextNode : thisNode->children) {
                    q.push(nextNode);
                }
            }
        }
        return ans;
    }
};