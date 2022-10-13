/*
 * @Author: LetMeFly
 * @Date: 2022-10-13 09:09:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-13 09:16:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 用数组
class Solution {
private:
    inline bool allAppeared(bool* bin, int to) {
        for (int i = 0; i <= to; i++)
            if (!bin[i])
                return false;
        return true;
    }
public:
    int maxChunksToSorted(vector<int>& arr) {
        bool bin[10] = {false};
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            bin[arr[i]] = true;
            if (allAppeared(bin, i))
                ans++;
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 记录最大值
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int M = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            M = max(M, arr[i]);
            ans += i == M;
        }
        return ans;
    }
};
#endif  // FirstTry