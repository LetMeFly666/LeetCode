/*
 * @Author: LetMeFly
 * @Date: 2025-04-19 20:43:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-13 22:44:38
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#include "2179.h"
#endif

/*
2 0 1 3
0 1 2 3
   ⬇️
0 1 2 3
1 2 0 3
   ⬇️
i左边小于p[i]的有less个
左边大于p[i]的有i-less个
大于p[i]的一共有n-p[i]-1个
右边大于p[i]的有n-p[i]-1-(i-less)个
*/

typedef long long ll;

class FenwickTree {
private:
    vector<int> v;
public:
    FenwickTree(int n) : v(n + 1) {}

    // 1 <= i <= n
    // 相当于v[i]加1
    void add(int i) {
        for (; i < v.size(); i += i & -i) {
            v[i]++;
        }
    }

    // 0 <= i < n
    // 相当于sum(1..i)
    int get(int i) {
        int ans = 0;
        for (; i > 0; i &= i - 1) {
            ans += v[i];
        }
        return ans;
    }
};

class Solution {
public:
    ll goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[nums1[i]] = nums2[i];
        }

        ll ans = 0;
        FenwickTree tree = FenwickTree(n);
        for (int i = 0; i < n; i++) {
            ll less = tree.get(p[i]);
            ans += less * (n - p[i] - 1 - (i - less));
            tree.add(p[i] + 1);
        }
        return ans;
    }
};