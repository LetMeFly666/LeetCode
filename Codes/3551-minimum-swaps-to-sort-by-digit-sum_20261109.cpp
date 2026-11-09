/*
 * @Author: LetMeFly
 * @Date: 2026-11-09 22:03:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-09 22:23:36
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class MyUnion {
private:
    int n, cnt;  // cnt是块数
    vector<int> fa;
    vector<int> sz;
    
    int getFa(int a) {
        return fa[a] == a ? a : (fa[a] = getFa(fa[a]));
    }
public:
    MyUnion(int n) : n(n), cnt(n), fa(n), sz(n) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    };

    int getCnt() {
        return cnt;
    }

    void merge(int a, int b) {
        int faa = getFa(a), fab = getFa(b);
        if (faa == fab) {
            return;
        }
        cnt--;
        int sa = sz[faa], sb = sz[fab];
        // 令a的fa为b
        if (sa > sb) {
            swap(faa, fab);
        }
        fa[faa] = fab;
        sz[fab] += sz[faa];
    }
};

class Solution {
private:
    int cal(int a) {
        int ans = 0;
        while (a) {
            ans += a % 10;
            a /= 10;
        }
        return ans;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> idxs(n);
        vector<int> vals(n);
        for (int i = 0; i < n; i++) {
            vals[i] = cal(nums[i]);
        }
        iota(idxs.begin(), idxs.end(), 0);
        ranges::sort(idxs, [&nums, &vals](const int& a, const int& b) {
            return vals[a] == vals[b] ? nums[a] < nums[b] : vals[a] < vals[b];
        });

        MyUnion myUnion(n);
        for (int i = 0; i < n; i++) {
            if (idxs[i] != i) {
                myUnion.merge(i, idxs[i]);
            }
        }
        return n - myUnion.getCnt();
    }
};

#ifdef _DEBUG
/*
[22,14,33,7]

0
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> a = stringToVector(s);
        Solution sol;
        cout << sol.minSwaps(a) << endl;
    }
    return 0;
}
#endif
