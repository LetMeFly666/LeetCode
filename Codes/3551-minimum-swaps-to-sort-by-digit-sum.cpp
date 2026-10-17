/*
 * @Author: LetMeFly
 * @Date: 2026-10-17 16:31:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-17 17:17:31
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<int> parent;
    vector<int> sz;

    int getSum(int a) {
        int ans = 0;
        while (a) {
            ans += a % 10;
            a /= 10;
        }
        return ans;
    }

    void initUnion(int n) {
        parent.resize(n);
        ranges
    }

    int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }

    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (sz[pa] > sz[pb]) {
            // swap(a, b);
            swap(pa, pb);
        }
        parent[pa] = pb;
        sz[pb] += sz[pa];
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> idxs(n);
        ranges::iota(nums, 0);
        sort(nums.begin(), nums.end(), [this, &nums](const int& a, const int& b) {
            int sa = getSum(a);
            int sb = getSum(b);
            return sa == sb ? a < b : sa < sb;
        });

        parent
    }
};
