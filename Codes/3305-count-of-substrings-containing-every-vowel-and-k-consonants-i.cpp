/*
 * @Author: LetMeFly
 * @Date: 2025-03-12 09:29:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-12 09:40:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static constexpr char yuanyin[] = "aeiou";
    
    inline bool allYuan(int* cnt) {
        for (int i = 0; i < 5; i++) {
            if (!cnt[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int countOfSubstrings(string word, int k) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            for (int j = i; j < word.size(); j++) {
                int cnt[5] = {0};
                int cntk = 0;
                for (int m = i; m <= j; m++) {
                    bool isYuan = false;
                    for (int n = 0; n < 5; n++) {
                        if (word[m] == yuanyin[n]) {
                            isYuan = true;
                            cnt[n]++;
                            break;
                        }
                    }
                    cntk += !isYuan;
                }
                ans += allYuan(cnt) && cntk == k;
            }
        }
        return ans;
    }
};