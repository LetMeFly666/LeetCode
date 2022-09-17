/*
 * @Author: LetMeFly
 * @Date: 2022-09-17 09:38:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-17 09:57:51
 */
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
vector<string> stringToVectorString(string s)  // [1,2,5]
{
    if (s == "[]")
        return {};
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

TreeNode* stringToTree(string s) {
    return vectorStringToTree(stringToVectorString(s));
}

string treeToString(TreeNode* root) {
    string ans = "[";
    queue<TreeNode*> q;
    q.push(root);
    bool first = true;
    string toAdd;  // 放置最后又一堆的null
    while (q.size()) {
        TreeNode* thisNode = q.front();
        q.pop();
        if (first) {
            first = false;
        }
        else {
            toAdd += ",";
        }
        if (thisNode) {
            ans += toAdd + to_string(thisNode->val);
            toAdd.clear();
            q.push(thisNode->left);
            q.push(thisNode->right);
        }
        else {
            toAdd += "null";
        }
    }
    ans += ']';
    return ans;
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
        return treeToString(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return stringToTree(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));