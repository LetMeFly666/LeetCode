/*
 * @Author: LetMeFly
 * @Date: 2022-04-23 10:58:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-23 10:59:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class NumArray {
private:
    vector<int>* p;
public:
    NumArray(vector<int>& nums) {
        p = &nums;
        nums.insert(nums.begin(), 0);
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return (*p)[right + 1] - (*p)[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */