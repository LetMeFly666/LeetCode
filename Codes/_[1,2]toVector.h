#pragma once
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

template<class Type>
void debug(vector<Type>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    puts("");
}

template<class Type>
void debug(vector<vector<Type>> v) {
    if (v.empty()) {
        puts("++\n++\n");
    }
    stringstream ss;
    bool first = true;
    for (auto t : v[0]) {
        if (first)
            first = false;
        else
            ss << ' ';
        ss << t;
    }
    string s;
    getline(ss, s);
    int l = s.size();

    function<void(int)> printOneline = [](int l) {
        putchar('+');
        for (int i = 0; i < l; i++) {
            putchar('-');
        }
        puts("+");
    };

    printOneline(l);
    for (auto tv : v) {
        putchar('|');
        bool first = true;
        for (auto t : tv) {
            if (first)
                first = false;
            else
                cout << ' ';
            cout << t;
        }
        puts("|");
    }
    printOneline(l);
}

template<class T>
void debug(T* a, int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

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

vector<vector<int>> stringToVectorVector(string s) //[[1,2,5],[2,5,6],[5,6]]
{
    vector<vector<int>>ans;
    s.erase(s.begin());
    s.erase(s.begin());
    s.erase(--s.end());
    s.erase(--s.end());
    vector<string> temp = split(s,"],[");
    for(string&s:temp)
    {
        s='['+s+']';
        ans.push_back(stringToVector(s));
    }
    return ans;
}

vector<char> stringToVectorC(string s)  // [1,2,5]
{
    vector<char>v;
    s=s.substr(1, s.size()).substr(0, s.size()-1);
    vector<string>vs=split(s, ',');
    for(int i=0;i<vs.size();i++)
    {
        string temp=vs[i];
        v.push_back(temp[1]);
    }
    return v;
}

vector<vector<char>> stringToVectorVectorC(string s) //[[1,2,5],[2,5,6],[5,6]]
{
    vector<vector<char>>ans;
    s.erase(s.begin());
    s.erase(s.begin());
    s.erase(--s.end());
    s.erase(--s.end());
    vector<string> temp = split(s,"],[");
    for(string&s:temp)
    {
        s='['+s+']';
        ans.push_back(stringToVectorC(s));
    }
    return ans;
}

vector<string> stringToVectorString(string s)  // [1,2,5]
{
    if (s == "[]")
        return {};
    vector<string>v;
    s=s.substr(1, s.size() - 1).substr(0, s.size() - 2);
    vector<string>vs=split(s, ',');
    for(int i=0;i<vs.size();i++)
    {
        string temp=vs[i];
        v.push_back(temp);
    }
    return v;
}

vector<string> stringToVectorStringWithQuots(string s) {  // ["1sfa","halj","LetMeFly"]
    vector<string>v;
    s = s.substr(1, s.size() - 1).substr(0, s.size() - 2);
    vector<string> vs = split(s, ',');
    for (int i = 0; i < vs.size(); i++) {
        string temp = vs[i];
        v.push_back(temp.substr(1, temp.size() - 1).substr(0, temp.size() - 2));
    }
    return v;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

TreeNode* vectorStringToTree(vector<string> v) {
    static bool first = true;
    if (first) {
        cout << "Don't forget to delete the Tree!" << endl;
        first = false;
    }

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

string oneNodeToString(TreeNode* root) {
    if (!root) return "NULL";
    else return to_string(root->val);
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

/* 低级debugTree */
void debug(TreeNode* root) {
    if (!root) return;
    cout << oneNodeToString(root) << "[" << oneNodeToString(root->left) << ", " << oneNodeToString(root->right) << "]" << endl;
    debug(root->left);
    debug(root->right);
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

void testForStringToVector()
{
    string s;
    while(cin>>s)
    {
        debug(stringToVector(s));
    }
    exit(0);
}

void testForSplitS()
{
    string s,c;
    while(cin>>s>>c)
    {
        debug(split(s,c));
    }
    exit(0);
}

// int main()
// {
//     testForStringToVector();
//     return 0;
// }

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