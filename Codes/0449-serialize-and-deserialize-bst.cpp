/*
 * @Author: LetMeFly
 * @Date: 2022-05-11 08:34:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-11 08:59:22
 */

#ifdef FirstTry_Fail

#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
vector<string> split(string toSplit, char c)  // 将字符串以字符c为间隔分开
{
    vector<string> ans;
    toSplit+=c;
    int left=0;
    for(int right=0;right<toSplit.size();right++)
    {
        if(toSplit[right]==c)  //left->right-1
        {
            ans.push_back(toSplit.substr(left,right-left));
            left=right+1;
        }
    }
    return ans;
}

vector<string> split(string toSplit, string c)  // 将字符串以字符串c为间隔分开
{
    vector<string> ans;
    toSplit+=c;
    int left=0;
    for(int right=0;right<toSplit.size()-c.size()+1;right++)
    {
        if(toSplit.substr(right,c.size())==c)  //left->right-1
        {
            ans.push_back(toSplit.substr(left,right-left));
            left=right+c.size();
        }
    }
    return ans;
}

vector<int> stringToVector(string s)  // [1,2,5]
{
    vector<int>v;
    s=s.substr(1, s.size()).substr(0, s.size()-1);
    vector<string>vs=split(s, ',');
    for(int i=0;i<vs.size();i++)
    {
        string temp=vs[i];
        int t;
        sscanf(temp.c_str(), "%d", &t);
        v.push_back(t);
    }
    return v;
}
TreeNode* vectorStringToTree(vector<string> v) {
    TreeNode* root;
    queue<TreeNode**> q;
    q.push(&root);
    for (int i = 0; i < v.size(); i++) {
        TreeNode** thisNodeP = q.front();
        q.pop();
        if (v[i] == "null") *thisNodeP = NULL;
        else {
            *thisNodeP = new TreeNode;
            int val;
            sscanf(v[i].c_str(), "%d", &val);
            (*thisNodeP)->val = val;
            (*thisNodeP)->left = NULL;
            (*thisNodeP)->right = NULL;
            q.push(&((*thisNodeP)->left));
            q.push(&((*thisNodeP)->right));
        }
    }
    return root;
}
vector<string> stringToVectorString(string s)  // [1,2,5]
{
    vector<string>v;
    s=s.substr(1, s.size()).substr(0, s.size()-1);
    vector<string>vs=split(s, ',');
    for(int i=0;i<vs.size();i++)
    {
        string temp=vs[i];
        v.push_back(temp);
    }
    return v;
}
TreeNode* stringToTree(string s) {
    return vectorStringToTree(stringToVectorString(s));
}
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "[";
        bool first = true;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (q.size()) {
            TreeNode* p = q.front();
            q.pop();
            // Begin print
            if (first)
                first = false;
            else
                ans += ",";
            if (p)
                ans += to_string(p->val);
            else
                ans += "null";
            // End print
            if (p) {
                if (p->right) {
                    q.push(p->left);
                    q.push(p->right);
                }
                else if (p->left) {
                    q.push(p->left);
                }
            }
        }
        ans += "]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        dbg(data);
        if (data == "[]")
            return nullptr;
        return stringToTree(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

#else

// copy from leetcode https://leetcode.cn/problems/serialize-and-deserialize-bst/solution/xu-lie-hua-he-fan-xu-lie-hua-er-cha-sou-5m9r4/
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Codec {
public:
    string serialize(TreeNode* root) {
        string res;
        vector<int> arr;
        postOrder(root, arr);
        if (arr.size() == 0) {
            return res;
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            res.append(to_string(arr[i]) + ",");
        }
        res.append(to_string(arr.back()));
        return res;
    }

    vector<string> split(const string &str, char dec) {
        int pos = 0;
        int start = 0;
        vector<string> res;
        while (pos < str.size()) {
            while (pos < str.size() && str[pos] == dec) {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != dec) {
                pos++;
            }
            if (start < str.size()) {
                res.emplace_back(str.substr(start, pos - start));
            }
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        vector<string> arr = split(data, ',');
        stack<int> st;
        for (auto & str : arr) {
            st.emplace(stoi(str));
        }
        return construct(INT_MIN, INT_MAX, st);
    }

    void postOrder(TreeNode *root,vector<int> & arr) {
        if (root == nullptr) {
            return;
        }
        postOrder(root->left, arr);
        postOrder(root->right, arr);
        arr.emplace_back(root->val);
    }

    TreeNode * construct(int lower, int upper, stack<int> & st) {
        if (st.size() == 0 || st.top() < lower || st.top() > upper) {
            return nullptr;
        }
        int val = st.top();
        st.pop();
        TreeNode *root = new TreeNode(val);
        root->right = construct(val, upper, st);
        root->left = construct(lower, val, st);
        return root;
    }
};

#endif