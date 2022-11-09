/*
 * @Author: LetMeFly
 * @Date: 2022-07-24 16:08:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-24 16:25:34
 */
#ifdef _WIN32
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
#endif


#ifdef FirstTry  // RE，难道不同的节点还会有相同的值？
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<int, Node*> ma;
        queue<Node*> q;
        assert(node);
        q.push(node);
        ma[node->val] = new Node(node->val);
        while (q.size()) {
            Node* thisNode = q.front();
            assert(thisNode);  //********
            q.pop();
            for (Node* to : thisNode->neighbors) {
                assert(to);  //************
                if (!ma.count(to->val)) {
                    ma[to->val] = new Node(to->val);
                    q.push(ma[to->val]);
                }
                thisNode->neighbors.push_back(ma[to->val]);
            }
        }
        return ma[node->val];
    }
};
#else  // FirstTry
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<Node*, Node*> ma;
        queue<Node*> q;
        q.push(node);
        ma[node] = new Node(node->val);
        while (q.size()) {
            Node* thisNode = q.front();
            q.pop();
            for (Node* to : thisNode->neighbors) {
                if (!ma.count(to)) {
                    ma[to] = new Node(to->val);
                    q.push(to);  // 这里是to
                }
                ma[thisNode]->neighbors.push_back(ma[to]);  // 这里是ma[thisNode]
            }
        }
        return ma[node];
    }
};
#endif  // FirstTry