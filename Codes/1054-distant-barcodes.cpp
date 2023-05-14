/*
 * @Author: LetMeFly
 * @Date: 2023-05-14 09:15:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-14 09:31:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // [1,1,1,1,2,2,3,3] -> [1,3,2,1,3,2,1,1]
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> ma;
        for (int t : barcodes) {
            ma[t]++;
        }
        vector<pair<int, int>> v(ma.begin(), ma.end());
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        vector<int> ans;
        while (v.size()) {
            vector<pair<int, int>> newV;
            for (pair<int, int>& p : v) {
                ans.push_back(p.first);
                p.second--;
                if (p.second) {
                    newV.push_back(p);
                }
            }
            swap(v, newV);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> ma;
        for (int t : barcodes) {
            ma[t]++;
        }
        sort(barcodes.begin(), barcodes.end(), [&](int a, int b) {
            return ma[a] != ma[b] ? ma[a] > ma[b] : a > b;
        });
        vector<int> ans(barcodes.size());
        for (int j = 0, k = 0; k < 2; k++) {
            for (int i = k; i < barcodes.size(); i += 2) {
                ans[i] = barcodes[j++];
            }
        }
        return ans;
    }
};
#endif  // FirstTry