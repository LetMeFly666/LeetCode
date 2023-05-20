/*
 * @Author: LetMeFly
 * @Date: 2023-05-20 09:51:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-20 10:34:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

struct MyNode {
    int minValue, maxValue, sumValue;
    bool isBST;
    MyNode(int minValue, int maxVlaue, int sumValue, bool isBST) : minValue(minValue), maxValue(maxValue), sumValue(sumValue), isBST(isBST) {};
};

// struct MyNode {
//     int minValue, maxValue, sumValue;
//     bool isBST;
//     MyNode(int minValue, int maxValue, int sumValue, bool isBST) : minValue(minValue), maxValue(maxValue), sumValue(sumValue), isBST(isBST) {};
// };

class Solution {
private:
    int ans;

    MyNode dfs(TreeNode* root) {
        if (!root) {
            return MyNode(INT_MAX, INT_MIN, 0, true);
        }
        MyNode left = dfs(root->left), right = dfs(root->right);
        // printf("root->value = %d\n", root->val);  //*******
        // if (root->left) printf("root->left = %d, left.isBST = %d, left.minValue = %d, left.maxValue = %d, left.sumValue = %d\n", root->left->val, left.isBST, left.minValue, left.maxValue, left.sumValue);  //*********
        // if (root->right) printf("root->right = %d, right.isBST = %d, right.minValue = %d, right.maxValue = %d, right.sumValue = %d\n", root->right->val, right.isBST, right.minValue, right.maxValue, right.sumValue);  //*********
        if (left.isBST && right.isBST && left.maxValue < root->val && right.minValue > root->val) {
            MyNode toReturn(min(left.minValue, root->val), max(right.maxValue, root->val), left.sumValue + right.sumValue + root->val, true);  // 这里min和max是因为left为空的话left.minValue为INT_MAX
            ans = max(ans, toReturn.sumValue);
            return toReturn;
        }
        else {
            return MyNode(0, 0, 0, false);
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};

#ifdef _WIN32
/*
[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]

*/
int main() {
    MyNode a(INT_MAX, INT_MIN, 0, true);
    dbg(a.maxValue);
    dbg(a.minValue);
    exit(0);
    string s;
    while (cin >> s) {
        TreeNode* root = stringToTree(s);
        Solution sol;
        cout << sol.maxSumBST(root) << endl;
        deleteTree(root);
    }
    return 0;
}
#endif