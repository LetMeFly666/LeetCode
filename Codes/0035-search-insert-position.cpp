#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};