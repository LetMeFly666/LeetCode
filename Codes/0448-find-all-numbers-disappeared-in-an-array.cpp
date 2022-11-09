/*
 * @Author: LetMeFly
 * @Date: 2022-10-20 09:07:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-20 09:48:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

#ifdef FirstTry  // 哈希表，空间O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> se;
        for (int& t : nums)
            se.insert(t);
        vector<int> ans;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            if (!se.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};
#else // FirstTry
#ifdef SecondTry  // 原地修改，把原始数组给改了
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int& t : nums) {
            int loc = abs(t) - 1;
            nums[loc] = -abs(nums[loc]);
        }
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};
#else  // SecondTry
// ThirdTry
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        int loc = 0;
        for (int to = 1; to <= n; to++) {
            while (loc < n && nums[loc] < to)
                loc++;
            if (loc == n || nums[loc] != to)
                ans.push_back(to);
        }
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry