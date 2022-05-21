/*
 * @Author: LetMeFly
 * @Date: 2022-04-25 08:53:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-25 09:01:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    map<int, vector<int>>ma;
public:
    Solution(vector<int>& nums) {
        srand(time(0));
        for (int i = 0; i < nums.size(); i++) {
            ma[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        map<int, vector<int>>::iterator it = ma.find(target);
        return it->second[rand() % it->second.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */