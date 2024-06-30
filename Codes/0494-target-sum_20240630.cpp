/*
 * @Author: LetMeFly
 * @Date: 2024-06-30 13:32:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-30 13:45:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 20*2^20T了 | 本地测试最大数据量0.142秒，但交上去还是超时了
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int state = 1 << nums.size();
        for (int i = 0; i < state; i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    cnt += nums[j];
                }
                else {
                    cnt -= nums[j];
                }
            }
            ans += cnt == target;
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
private:
    int ans;

    void dfs(vector<int>& nums, int target, int loc) {
        if (loc == nums.size()) {
            ans += target == 0;
            return;
        }
        dfs(nums, target - nums[loc], loc + 1);
        dfs(nums, target + nums[loc], loc + 1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        ans = 0;
        dfs(nums, target, 0);
        return ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
#include <windows.h>
int main() {
    vector<int> nums = {25, 18, 47, 13, 45, 29, 15, 45, 33, 19, 39, 15, 39, 45, 17, 21, 29, 43, 50, 10};  // 20个
    Solution sol;
    time_t start = clock();
    cout << sol.findTargetSumWays(nums, 25) << endl;
    time_t end = clock();
    cout << "Time consume: " << 1. * (end - start) / CLOCKS_PER_SEC << endl;
    time_t testBegin = clock();
    Sleep(1000);
    time_t testEnd = clock();
    cout << "Time test 1s: " << 1. * (testEnd - testBegin) / CLOCKS_PER_SEC << endl;
    return 0;
}
#endif