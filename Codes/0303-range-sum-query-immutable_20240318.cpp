/*
 * @Author: LetMeFly
 * @Date: 2024-03-18 10:03:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-18 10:05:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */