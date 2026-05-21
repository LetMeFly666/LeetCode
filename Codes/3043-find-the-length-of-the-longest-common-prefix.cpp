/*
 * @Author: LetMeFly
 * @Date: 2026-05-21 22:00:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-21 22:32:19
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int len(int t) {
        int ans = 0;
        while (t) {
            ans++;
            t /= 10;
        }
        return ans;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> can;
        for (int t : arr1) {
            while (t) {
                can.insert(t);
                t /= 10;
            }
        }
        
        int ans = 0;
        for (int t : arr2) {
            while (t) {
                if (can.count(t)) {
                    ans = max(ans, len(t));
                    break;
                }
                t /= 10;
            }
        }
        return ans;
    }
};
