/*
 * @Author: LetMeFly
 * @Date: 2026-01-22 23:30:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-22 23:47:47
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

template<class Type>
void debug(vector<Type>v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    puts("");
}

class Solution {
private:
    bool finished(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // len(nums)一定大于等于2
    int getMinPairIdx(vector<int>& nums) {
        int idx = 0, mini = 50001;  // 这里不能是2001
        for (int i = 0; i + 1 < nums.size(); i++) {
            int cnt = nums[i] + nums[i + 1];
            if (cnt < mini) {
                mini = cnt;
                idx = i;
            }
        }
        return idx;
    }

    vector<int> merge(vector<int>& nums, int idx) {
        vector<int> ans;
        for (int i = 0; i < idx; i++) {
            ans.push_back(nums[i]);
        }
        ans.push_back(nums[idx] + nums[idx + 1]);
        for (int i = idx + 2; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!finished(nums)) {
            int idx = getMinPairIdx(nums);
            nums = merge(nums, idx);
            // debug(nums);
            ans++;  // don't forgot
        }
        return ans;
    }
};

/*
[689,-360,234,673,663,-741,480,860,-707,209,246,792,930,696,-305]

My:
689 -360 234 673 663 -741 480 860 -498 246 792 930 696 -305 
689 -360 234 673 663 -261 860 -498 246 792 930 696 -305 
689 -360 234 673 663 -261 860 -252 792 930 696 -305 
689 -126 673 663 -261 860 -252 792 930 696 -305 
689 -126 673 663 -261 860 -252 792 930 391 
689 -126 673 402 860 -252 792 930 391 
689 -126 673 402 860 540 930 391 
689 547 402 860 540 930 391 
689 949 860 540 930 391 
689 949 860 540 1321 
689 949 1400 1321 
1638 1400 1321   <-----应该merge后俩
3038 1321 
4359 

14


should:
689 -360 234 673 663 -741 480 860 -498 246 792 930 696 -305 
689 -360 234 673 663 -261 860 -498 246 792 930 696 -305 
689 -360 234 673 663 -261 860 -252 792 930 696 -305
689 -126 673 663 -261 860 -252 792 930 696 -305
689 -126 673 663 -261 860 -252 792 930 391
689 -126 673 402 860 -252 792 930 391
689 -126 673 402 860 540 930 391
689 547 402 860 540 930 391
689 949 860 540 930 391
689 949 860 540 1321
689 949 1400 1321
1638 1400 1321
1638 2721

13
*/