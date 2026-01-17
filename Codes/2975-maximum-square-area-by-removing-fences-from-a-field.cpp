/*
 * @Author: LetMeFly
 * @Date: 2026-01-17 21:02:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-17 21:08:43
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_set<int> get(int n, vector<int>& v) {
        v.push_back(1);
        v.push_back(n);
        unordered_set<int> ans;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                ans.insert(abs(v[i] - v[j]));
            }
        }
        return ans;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> va = get(m, hFences), vb = get(n, vFences);
        int side = 0;
        for (int a : va) {
            if (vb.count(a)) {
                side = max(side, a);
            }
        }
        return side ? (long long) side * side % 1000000007 : -1;
    }
};