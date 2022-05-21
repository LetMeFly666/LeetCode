/*
 * @Author: LetMeFly
 * @Date: 2022-04-08 08:31:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-08 08:36:27
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

typedef pair<Node*, int> pii;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<pii> q;
        q.push({root, 0});
        int lastLayer = 0;
        vector<int> layer;
        while (q.size()) {
            pii thisPair = q.front();
            q.pop();
            if (thisPair.second != lastLayer) {
                ans.push_back(layer);
                lastLayer = thisPair.second;
                layer.clear();
            }
            layer.push_back(thisPair.first->val);
            for (Node* to : thisPair.first->children) {
                q.push({to, thisPair.second + 1});
            }
        }
        ans.push_back(layer);
        return ans;
    }
};