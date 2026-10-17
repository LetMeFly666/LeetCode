/*
 * @Author: LetMeFly
 * @Date: 2026-10-17 16:31:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-17 18:40:12
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#else
template<class Type>
void debug(vector<Type>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    puts("");
}
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
        ranges::iota(parent, 0);
        sz.resize(n);
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
        return true;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> idxs(n);
        ranges::iota(idxs, 0);
        sort(idxs.begin(), idxs.end(), [this, &nums](const int& a, const int& b) {
            int sa = getSum(nums[a]);
            int sb = getSum(nums[b]);
            return sa == sb ? nums[a] < nums[b] : sa < sb;
        });
        // debug(idxs);

        int ans = nums.size();
        initUnion(n);
        for (int i = 0; i < n; i++) {
            ans -= !unite(i, idxs[i]);
        }
        return ans;
    }
};
