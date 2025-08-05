/*
 * @Author: LetMeFly
 * @Date: 2025-08-05 10:28:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-05 10:31:43
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int, int> window;
        for (int l = 0, r = 0; r < fruits.size(); r++) {
            window[fruits[r]]++;
            while (window.size() > 2) {
                if (! --window[fruits[l]]) {
                    window.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};