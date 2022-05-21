/*
 * @Author: LetMeFly
 * @Date: 2022-03-10 17:26:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-11 09:23:17
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

#ifdef FirstTime
// 2022-3-10
class Solution {
private:
    vector<int> ans;

    void dfs(Node* root) {
        if (!root)
            return;
        ans.push_back(root->val);
        for (auto& c : root->children) {
            dfs(c);
        }
    }
public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};
#else
// 2022-4-11
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
            return;
        ans.push_back(root->val);
        for (auto& child : root->children) {
            dfs(child);
        }    
    }
public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};
#endif