/*
 * @Author: LetMeFly
 * @Date: 2025-05-12 10:20:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-12 22:35:40
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int cnt[10] = {0};

    bool isOk(int i) {
        if (i % 2) {
            return false;
        }
        int temp[10] = {0};
        while (i) {
            temp[i % 10]++;
            i /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (cnt[i] < temp[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        for (int d : digits) {
            cnt[d]++;
        }
        vector<int> ans;
        for (int i = 100; i < 1000; i++) {
            if (isOk(i)) {
                ans.push_back(i);
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};