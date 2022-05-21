/*
 * @Author: LetMeFly
 * @Date: 2022-04-29 08:33:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-29 09:03:18
 */
#ifdef _WIN32
// #include "_[1,2]toVector.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

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
#endif

#define dbg(x) cout << #x << " = " << x << endl

class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int l = -1, int startX = -1, int startY = -1) {
        Node* root = new Node();
        if (l == -1) {
            l = grid.size();
            startX = startY = 0;
        }
        // printf("l = %d, start: [%d, %d]\n", l, startX, startY);  //*****
        bool same = true;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (grid[i + startX][j + startY] != grid[startX][startY]) {
                    same = false;
                    goto loop;
                }
            }
        }
        loop:;
        if (same) {
            root->isLeaf = true;
            root->val = (grid[startX][startY] != 0);
        }
        else {
            root->isLeaf = false;
            root->topLeft = construct(grid, l / 2, startX, startY);
            root->topRight = construct(grid, l / 2, startX, startY + l / 2);
            root->bottomLeft = construct(grid, l / 2, startX + l / 2, startY);
            root->bottomRight = construct(grid, l / 2, startX + l / 2, startY + l / 2);
        }
        return root;
    }
};

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<vector<int>> v = stringToVectorVector(s);
        sol.construct(v);
    }
    return 0;
}
#endif