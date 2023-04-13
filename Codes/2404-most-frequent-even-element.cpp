/*
 * @Author: LetMeFly
 * @Date: 2023-04-13 13:10:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-13 18:13:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 排序 + 哈希表
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> ma;
        int M = 0, ans = -1;
        for (int& n : nums) {
            if (n % 2 == 0) {
                ma[n]++;
                if (ma[n] > M) {
                    M = ma[n];
                    ans = n;
                }
            }
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // 哈希表
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> ma;
        int M = 0, ans = 1e8;
        for (int& n : nums) {
            if (n % 2 == 0) {
                ma[n]++;
                // printf("n = %d, ma[%d] = %d, M = %d\n", n, n, ma[n], M);  //**************
                if (ma[n] > M) {
                    M = ma[n];
                    ans = n;
                }
                else if (ma[n] == M) {
                    ans = min(ans, n);
                }
            }
        }
        return ans == 1e8 ? -1 : ans;
    }
};
#else  // SecondTry
// ThirdTry
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int M = 0, ans = -1;
        int beginLoc = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] != nums[i - 1]) {
                if (nums[i - 1] % 2 == 0) {
                    int thisCnt = i - beginLoc;
                    if (thisCnt > M) {
                        M = thisCnt;
                        ans = nums[i - 1];
                    }
                }
                beginLoc = i;
            }
        }
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry