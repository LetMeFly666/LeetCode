/*
 * @Author: LetMeFly
 * @Date: 2022-06-26 07:01:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-26 07:58:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<int> smallCan;  // 小范围数据可选取
    int n;
    int smallTo;
    int smallNum, allNum;
public:
    Solution(int n, vector<int>& blacklist): n(n) {
        sort(blacklist.begin(), blacklist.end());
        int loc = 0;
        int size = blacklist.size();
        smallTo = min(100000, n);
        for (int i = 0; i < smallTo; i++) {
            if (loc == size)
                smallCan.push_back(i);
            else {
                if (i == blacklist[loc]) {  // blacklist 中所有值都 不同
                    loc++;
                }
                else {
                    smallCan.push_back(i);
                }
            }
        }
        smallNum = smallCan.size();
        allNum = smallNum + (n - smallTo);
    }
    
    int pick() {
        int th = rand() % allNum;
        if (th < smallNum) {
            return smallCan[th];
        }
        else {
            return smallTo + (th - smallNum);
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */