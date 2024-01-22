/*
 * @Author: LetMeFly
 * @Date: 2024-01-22 12:36:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-22 12:45:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    string s;
    
    int getFirstIncreaseLoc() {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] > s[i - 1]) {
                return i;
            }
        }
        return s.size();
    }
    
    int getMaxLocFromA(int a) {
        int ans = a;
        int M = s[a];
        for (; a < s.size(); a++) {
            if (s[a] >= M) {
                ans = a;
                M = s[a];
            }
        }
        return ans;
    }

    int getFirstLessthanLoc(char n) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < n) {
                return i;
            }
        }
        return s.size();  // Fake Return
    }
public:
    int maximumSwap(int num) {
        s = to_string(num);
        int firstIncreaseLoc = getFirstIncreaseLoc();
        if (firstIncreaseLoc == s.size()) {
            return num;
        }
        int maxLoc = getMaxLocFromA(firstIncreaseLoc);
        int firstLessthanLoc = getFirstLessthanLoc(s[maxLoc]);
        swap(s[firstLessthanLoc], s[maxLoc]);
        return atoi(s.c_str());
    }
};