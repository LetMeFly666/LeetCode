/*
 * @Author: LetMeFly
 * @Date: 2021-12-25 08:24:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-25 14:53:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<TreeNode*, int> pii;
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        auto check = [&](int val, int ceng) {return val % 2 == ceng % 2;};
        if (!check(root->val, 1)) return false;
        queue<pii> q;
        q.emplace(root, 1);
        int lastFloor = 0;
        int lastVal;
        while (q.size()) {
            pii thisPair = q.front();
            q.pop();
            if (thisPair.second != lastFloor) {
                lastFloor = thisPair.second;
            }
            else {
                if (thisPair.second % 2) { // 应递增
                    if (thisPair.first->val <= lastVal) return false;
                }
                else {
                    if (thisPair.first->val >= lastVal) return false;
                }
            }
            lastVal = thisPair.first->val;
            if (thisPair.first->left) {
                if (!check(thisPair.first->left->val, thisPair.second + 1)) return false;
                q.emplace(thisPair.first->left, thisPair.second + 1);
            }
            if (thisPair.first->right) {
                if (!check(thisPair.first->right->val, thisPair.second + 1)) return false;
                q.emplace(thisPair.first->right, thisPair.second + 1);
            }
        }
        return true;
    }
};

#ifdef _WIN32

/* 输出n个c */
template<class T>
void prt(T c, int n) {
    for (int i = 0; i < n; i++)
        cout << c;
}

// 获取节点占用的总长度、节点中点及其距左边的距离
tuple<int, int> getLengthAndMiddle(TreeNode* root) {
    static map<TreeNode*, tuple<int, int>> ma;
    if (!root) return {0, 0};
    if (ma.count(root)) return ma[root];
    int leftLength = get<0, int, int>(getLengthAndMiddle(root->left));
    int selfLength = to_string(root->val).size();
    int rightLength = get<0, int, int>(getLengthAndMiddle(root->right));
    int midLength = leftLength + 1 + (selfLength + 1) / 2;
    int allLength = leftLength + 1 + midLength + 1 + rightLength;
    return ma[root] = {allLength, midLength};
}

void debug(vector<vector<TreeNode*>> layers) {
    int layer = 0;
    for (vector<TreeNode*>& thisLayer : layers) {
        cout << "layer" << layer << ": ";
        bool first = true;
        for (TreeNode* &thisNode : thisLayer) {
            if (first) first = false;
            else cout << ", ";
            cout << thisNode->val;
        }
        puts("");
    }
}

vector<vector<TreeNode*>> splitLayer(TreeNode* root) { // 将树分为一层一层的
    queue<pair<TreeNode*, int>> q; // <TreeNode, Layer>
    vector<vector<TreeNode*>> layers;
    vector<TreeNode*> thisLayer;
    if (!root) return layers;
    int lastLayer = 0;
    q.emplace(root, 0);
    while (q.size()) {
        pair<TreeNode*, int> thisPair = q.front();
        q.pop();
        if (thisPair.second != lastLayer) {
            layers.push_back(thisLayer);
            thisLayer.clear();
        }
        lastLayer = thisPair.second;
        thisLayer.push_back(thisPair.first);
        if (thisPair.first->left) q.emplace(thisPair.first->left, thisPair.second + 1);
        if (thisPair.first->right) q.emplace(thisPair.first->right, thisPair.second + 1);
    }
    layers.push_back(thisLayer);
    return layers;
}

// 控制台中以树的形式打印一棵树
void printTree(TreeNode* root) {
    vector<vector<TreeNode*>> layers = splitLayer(root);
    for (vector<TreeNode*> thisLayer : layers) {

    }
    auto[leftAllLength, leftMiddleLength] = getLengthAndMiddle(root);
    prt(' ', leftAllLength + 1);
    cout << (root->val);
}

/*
[5,2,131]

*/
int main() {
    string s;
    while (cin >> s) {
        TreeNode* root = stringToTree(s);
        debug(root);
        printTree(root);
        puts("\n------");
        Solution sol;
        cout << sol.isEvenOddTree(root) << endl;
        deleteTree(root);
    }
//     printf("\
//     5\n\
// +---+----+\n\
// |        |\n\
// 2       131\n");
//     system("pause");
    return 0;
}
#endif