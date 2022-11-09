/*
 * @Author: LetMeFly
 * @Date: 2022-11-03 08:11:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-03 08:24:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 20*2^20T了
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size(), to = 1 << n;
        for (int i = 0; i < to; i++) {
            int thisResult = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    thisResult += nums[j];
                else
                    thisResult -= nums[j];
            }
            ans += thisResult == target;
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // Copy
class Solution {
public:
    int count = 0;

    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }

    void backtrack(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                count++;
            }
        } else {
            backtrack(nums, target, index + 1, sum + nums[index]);
            backtrack(nums, target, index + 1, sum - nums[index]);
        }
    }
};
#endif  // FirstTry
#ifdef _WIN32
/*
[35,25,24,23,2,47,39,22,3,7,11,26,6,30,5,34,10,43,41,28]
49


*/
int main() {
    string s;
    int n;
    while (cin >> s >> n) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.findTargetSumWays(v, n) << endl;
    }
    return 0;
}
#endif