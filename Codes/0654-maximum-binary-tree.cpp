/*
 * @Author: LetMeFly
 * @Date: 2022-08-20 09:56:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-20 10:37:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
ostream& operator << (ostream& ostr, TreeNode* node) {
    if (!node) {
        ostr << "nullptr";
    }
    else {
        ostr << node->val << "[";
        // ostr << (node->left ? node->left->val : "nullptr") << ", ";
        if (node->left) {
            ostr << node->left->val;
        }
        else {
            ostr << "nullptr";
        }
        ostr << ", ";
        if (node->right) {
            ostr << node->right->val;
        }
        else {
            ostr << "nullptr";
        }
        ostr << "]";
    }
    return ostr;
}
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
#ifdef FirstTry  // 方法一：递归，O(n^2) O(n)
class Solution {
private:
    TreeNode* main(vector<int>::iterator l, vector<int>::iterator r) {
        if (l >= r)
            return nullptr;
        vector<int>::iterator maxIt = l;
        int maxVal = *l;
        for (vector<int>::iterator it = l; it != r; it++) {
            if (*it > maxVal) {
                maxVal = *it;
                maxIt = it;
            }
        }
        return new TreeNode(maxVal, main(l, maxIt), main(maxIt + 1, r));
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return main(nums.begin(), nums.end());
    }
};
#else  // FirstTry
// SecondTry  // 方法二，单调栈，O(n)，O(n)



void debug(stack<TreeNode*> st) {
    stack<TreeNode*> toReverse;
    while (st.size()) {
        toReverse.push(st.top());
        st.pop();
    }
    bool first = true;
    while (toReverse.size()) {
        if (first) {
            first = false;
            printf("[");
        }
        else {
            printf(", ");
        }
        cout << toReverse.top();
        toReverse.pop();
    }
    puts("]");
}

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;
        for (int &t : nums) {
            TreeNode* thisNode = new TreeNode(t);
            while (st.size() && st.top()->val < t) {
                thisNode->left = st.top();
                st.pop();
            }
            if (st.size()) {
                st.top()->right = thisNode;
            }
            st.push(thisNode);
            // printf("thisNum: %d\n", t);
            // debug(st);
        }
        TreeNode* ans;
        while (st.size()) {
            ans = st.top();
            st.pop();
        }
        return ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        TreeNode* root = sol.constructMaximumBinaryTree(v);
        debug(root);
    }
    return 0;
}
#endif