/*
 * @Author: LetMeFly
 * @Date: 2022-08-27 13:08:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-27 14:54:07
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
#ifdef FirstTry  // 横纵坐标 // Error
typedef pair<TreeNode*, int> pii;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pii>q;
        q.push({root, 0});
        while (q.size()) {
            int l = 0, r = 0;
            for (int i = q.size(); i > 0; i--) {
                auto[node, loc] = q.front();
                q.pop();
                l = min(l, loc), r = max(r, loc);
                if (node->left) {
                    q.push({node->left, loc - 1});
                }
                if (node->right) {
                    q.push({node->right, loc});
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // TLE  // 可能会特别膨胀
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int thisLayerNum = q.size();
            int mostL = thisLayerNum,  mostR = 0;
            for (int i = 0; i < thisLayerNum; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    mostL = min(mostL, i);
                    mostR = max(mostR, i);
                    q.push(node->left);
                    q.push(node->right);
                }
                else {
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
            if (mostL == thisLayerNum) {  // 说明mostL没变，也就是说这一层全是NULL
                break;
            }
            ans = max(ans, mostR - mostL + 1);
        }
        return ans;
    }
};
#else  // SecondTry
//  ThirdTry
typedef unsigned long long ull;
// typedef __int128 ull;
typedef pair<TreeNode*, ull> pii;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ull ans = 0;
        queue<pii> q;
        q.push({root, 1});
        ull lastL, lastR;
        // int cntDebug = 0;
        while (q.size()) {
            
            // cntDebug++;
            // if (cntDebug > 1750) {
            //     printf("q.size() = %lld, q:[");
            //     // queue<pii> q2, q3 = q;
            //     // while (q3.size()) {
            //     //     q2.push(q3.front());
            //     //     q3.pop();
            //     // }
            //     // while (q2.size()) {
            //     //     cout << q2.front().first->val << ", ";
            //     // }
            // }
            ull mostL = q.front().second, mostR = mostL;
            for (int i = q.size(); i > 0; i--) {
                auto[node, loc] = q.front();
                // printf("loc = %llu\n", loc);
                // if (node->val) {
                //     printf("node->val = %d, loc = %llu\n", node->val, loc);
                // }
                q.pop();
                mostL = min(mostL, loc);
                mostR = max(mostR, loc);
                if (node->left) {
                    q.push({node->left, loc * 2 - 1});
                }
                if (node->right) {
                    q.push({node->right, loc * 2});
                }
            }
            lastL = mostL, lastR = mostR;
            ans = max(ans, mostR - mostL + 1);
            // if (cntDebug > 1750) {
            //     // cout << "mostL = " << lastL << ", mostR = " << lastR << endl;
            //     printf("mostL = %llu, mostR = %llu\n", mostL, mostR, q.size());
            // }
        }
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry


// // 官方题解 + 修改 + Error
// typedef unsigned long long ull;
// typedef pair<TreeNode*, ull> pii;
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         ull res = 1;
//         queue<pii> arr;
//         arr.push({root, 1});
//         while (!arr.empty()) {
//             queue<pii>  tmp;
//             ull mostL = arr.front().second, mostR = mostL;
//             while (arr.size()) {
//                 auto [node, index] = arr.front();
//                 mostL = min(mostL, index);
//                 mostR = max(mostR, index);
//                 arr.pop();
//                 if (node->left) {
//                     tmp.push({node->left, index * 2 - 1});
//                 }
//                 if (node->right) {
//                     tmp.push({node->right, index * 2});
//                 }
//             }
//             res = max(res, mostR - mostL + 1);
//             arr = move(tmp);
//         }
//         return res;
//     }
// };

// // 官解 + assert
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         unsigned long long res = 1;
//         vector<pair<TreeNode *, unsigned long long>> arr;
//         arr.emplace_back(root, 1L);
//         while (!arr.empty()) {
//             vector<pair<TreeNode *, unsigned long long>> tmp;
//             for (auto &[node, index] : arr) {
//                 if (node->left) {
//                     tmp.emplace_back(node->left, index * 2 - 1);
//                 }
//                 if (node->right) {
//                     tmp.emplace_back(node->right, index * 2);
//                 }
//                 assert(index * 2 > index);
//             }
//             res = max(res, arr.back().second - arr[0].second + 1);
//             arr = move(tmp);
//         }
//         return res;
//     }
// };