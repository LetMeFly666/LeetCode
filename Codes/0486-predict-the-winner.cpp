/*
 * @Author: LetMeFly
 * @Date: 2022-11-01 21:41:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-01 21:57:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 这只是枚举1是否有赢的可能，但每人走的并不是最优
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), to = 1 << n;
        for (int state = 0; state < to; state++) {
            int l = 0, r = n - 1;
            int score[2] = {0};
            for (int i = 0; i < n; i++) {
                if (state & (1 << i)) {
                    score[i % 2] += nums[l++];
                }
                else {
                    score[i % 2] += nums[r--];
                }
            }
            if (score[0] >= score[1])
                return true;
        }
        return false;
    }
};
#else  // FirstTry
class Solution {
private:
    int bestScore(vector<int>& nums, int l, int r, int k) {
        if (l == r)
            return nums[l] * k;
        int scoreFront = nums[l] * k + bestScore(nums, l + 1, r, -k);
        int scoreBack = nums[r] * k + bestScore(nums, l, r - 1, -k);
        return max(abs(scoreFront), abs(scoreBack)) * k;
        // return max(scoreFront * k, scoreBack * k) * k;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return bestScore(nums, 0, nums.size() - 1, 1) >= 0;
    }
};
#endif  // FirstTry