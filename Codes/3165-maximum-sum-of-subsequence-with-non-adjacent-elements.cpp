/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 11:45:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 12:21:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const unsigned int mod = 1e9 + 7;

class Solution {
private:
    vector<array<unsigned int, 4>> tree;  // 00, 01, 10, 11

    void maintain(int index) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        tree[index] = {
            max(tree[leftIndex][1] + tree[rightIndex][0], tree[leftIndex][0] + tree[rightIndex][2]),
            max(tree[leftIndex][0] + tree[rightIndex][3], tree[leftIndex][1] + tree[rightIndex][1]),
            max(tree[leftIndex][2] + tree[rightIndex][2], tree[leftIndex][3] + tree[rightIndex][0]),
            max(tree[leftIndex][2] + tree[rightIndex][3], tree[leftIndex][3] + tree[rightIndex][1])
        };
    }

    void buildTree(vector<int>& nums, int index, int left, int right) {
        if (left == right) {
            tree[index] = {0, 0, 0, (unsigned int)max(nums[left], 0)};
            return;
        }
        int mid = (left + right) / 2;
        buildTree(nums, 2 * index + 1, left, mid);
        buildTree(nums, 2 * index + 2, mid + 1, right);
        maintain(index);
    }

    void update(int index, int left, int right, int modifiedI, int val) {
        if (left == right) {
            tree[index][3] = max(0, val);
            return;
        }
        int mid = (left + right) / 2;
        if (modifiedI <= mid) {
            update(2 * index + 1, left, mid, modifiedI, val);
        } else {
            update(2 * index + 2, mid + 1, right, modifiedI, val);
        }
        maintain(index);
    }
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        tree.resize(nums.size() * 4);
        buildTree(nums, 0, 0, nums.size() - 1);
        unsigned int ans = 0;
        for (vector<int>& query : queries) {
            update(0, 0, nums.size() - 1, query[0], query[1]);
            ans = (ans + tree[0][3]) % mod;
        }
        return ans;
    }
};