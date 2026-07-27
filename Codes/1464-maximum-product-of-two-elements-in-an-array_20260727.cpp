#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 1, mx2 = 1;
        for (int t : nums) {
            if (t > mx2) {
                mx1 = mx2;
                mx2 = t;
            } else if (t > mx1) {
                mx1 = t;
            }
        }
        return (mx1 - 1) * (mx2 - 1);
    }
};
