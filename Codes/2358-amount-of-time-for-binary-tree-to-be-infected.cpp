/*
 * @Author: LetMeFly
 * @Date: 2024-04-24 22:19:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-24 22:44:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#ifdef FirstTry  // TLE
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> fathers;
    int start;
    TreeNode* startNode;

    void dfs(TreeNode* root, TreeNode* father) {
        if (!root) {
            return;
        }
        fathers[root] = father;
        if (root->val == start) {
            startNode = root;
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        dfs(root, nullptr);
        int ans = -1;
        queue<TreeNode*> q;
        q.push(startNode);
        startNode->val = 0;
        while (q.size()) {
            ans++;
            for (int t = q.size(); t > 0; t--) {
                TreeNode* thisNode = q.front();
                q.pop();
                for (TreeNode* nextNode : vector<TreeNode*> {thisNode->left, thisNode->right, fathers[thisNode]}) {
                    if ((!nextNode) || (!(nextNode->val))) {
                        continue;
                    }
                    printf("push[nextNode=%d]\n", nextNode->val);  //*******
                    nextNode->val = 0;
                    q.push(nextNode);
                }
            }
        }
        return ans;
    }
};
#else  // FirstTry
class Solution {
private:
    unordered_map<int, vector<int>> neighbors;

    void dfs(TreeNode* root) {
        if (root->left) {
            neighbors[root->val].push_back(root->left->val);
            neighbors[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if (root->right) {
            neighbors[root->val].push_back(root->right->val);
            neighbors[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        int ans = -1;
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        while (q.size()) {
            ans++;
            for (int t = q.size(); t > 0; t--) {
                int thisNode = q.front();
                q.pop();
                for (int nextNode : neighbors[thisNode]) {
                    if (!visited.count(nextNode)) {
                        visited.insert(nextNode);
                        q.push(nextNode);
                    }
                }
            }
        }
        return ans;
    }
};
#endif  // FirstTry