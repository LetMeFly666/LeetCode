/*
 * @Author: LetMeFly
 * @Date: 2022-05-21 10:50:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-21 13:56:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef Method1
// 方法一：排序
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;  // Fake return：LeetCode编译器必须要求有一个返回值
    }
};
#else  // Method1
#ifdef SecondMethod
// 方法二：哈希表
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> appended;  // 记录已经出现过的元素
        for (int& t : nums) {  // 遍历
            if (appended.count(t)) {  // 出现过
                return t;
            }
            appended.insert(t);
        }
        return -1;  // Fake return
    }
};
#else  // SecondMethod
#ifdef MethodThree
// 方法三：数学
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if (nums.size() == 4) {  // n = 2时特判
            for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 4; j++) {
                    if (nums[i] == nums[j]) {
                        return nums[i];
                    }
                }
            }
        }
        // n > 2
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                return nums[i];
            }
            if (i + 2 < nums.size() && nums[i + 2] == nums[i]) {
                return nums[i];
            }
        }
        return -1;  // Fake return
    }
};
#else  // MethodThree
#ifdef MethodFour_Wrong
// 方法四：随机选择：错误示范
// 不可以这样写，因为这样可能会选取两个相同的下标
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        srand(time(NULL));
        int location;
        do {
            location = rand() % nums.size();
        } while (nums[location] != nums[rand() % nums.size()]);
        return nums[location];
    }
};
#else  // MethodFour_Wrong
// 方法四：随机选择：正确方法
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        srand(time(NULL));
        int loc1, loc2;
        do {
            loc1 = rand() % nums.size();
            loc2 = rand() % nums.size();
        } while (nums[loc1] != nums[loc2]);
        return nums[loc1];
    }
};
#endif  // MethodFour_Wrong
#endif  // MethodThree
#endif  // SecondMethod
#endif  // Method1