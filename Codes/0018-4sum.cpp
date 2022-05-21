/*
 * @Author: LetMeFly
 * @Date: 2022-05-10 13:58:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-10 14:12:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry_AndChanged
// 好吧，没看清题目是互不相同的答案
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int, int> ma;
        vector<vector<int>> ans;
        for (int t : nums) {
            ma[t]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    ma[nums[i]]--, ma[nums[j]]--, ma[nums[k]]--;
                    if (ma[target - nums[i] - nums[j] - nums[k]] > 0) {
                        vector<int> thisVector;
                        thisVector.push_back(nums[i]);
                        thisVector.push_back(nums[j]);
                        thisVector.push_back(nums[k]);
                        thisVector.push_back(target - nums[i] - nums[j] - nums[k]);
                        sort(thisVector.begin(), thisVector.end());
                        for (int times = ma[target - nums[i] - nums[j] - nums[k]]; times > 0; times--) {
                            ans.push_back(thisVector);
                        }
                    }
                    ma[nums[i]]++, ma[nums[j]]++, ma[nums[k]]++;
                }
            }
        }
        #ifdef _WIN32
        puts("--------------------");
        debug(ans);
        puts("--------------------"); 
        #endif
        sort(ans.begin(), ans.end());
        vector<vector<int>> realAns;
        for (int i = 0; i < ans.size(); i += 3) {
            realAns.push_back(ans[i]);
        }
        return realAns;
    }
};
#else
#ifdef SecondTry
// 暴力TLE  282 / 289 个通过测试用例
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int, int> ma;
        set<vector<int>> se;
        for (int t : nums) {
            ma[t]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    ma[nums[i]]--, ma[nums[j]]--, ma[nums[k]]--;
                    if (ma[target - nums[i] - nums[j] - nums[k]] > 0) {
                        vector<int> thisVector;
                        thisVector.push_back(nums[i]);
                        thisVector.push_back(nums[j]);
                        thisVector.push_back(nums[k]);
                        thisVector.push_back(target - nums[i] - nums[j] - nums[k]);
                        sort(thisVector.begin(), thisVector.end());
                        se.insert(thisVector);
                    }
                    ma[nums[i]]++, ma[nums[j]]++, ma[nums[k]]++;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto& v : se) {
            ans.push_back(v);
        }
        return ans;
    }
};
#else
// Copy from LeetCode
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4) {
            return quadruplets;
        }
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;
                }
                int left = j + 1, right = length - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }
};
#endif
#endif

#ifdef _WIN32
int main() {
    string s;
    int n;
    while (cin >> s >> n) {
        Solution sol;
        vector<int> v = stringToVector(s);
        debug(sol.fourSum(v, n));
    }
    return 0;
}
#endif