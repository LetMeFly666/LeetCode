/*
 * @Author: LetMeFly
 * @Date: 2025-03-13 10:24:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-13 10:34:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
private:
    static constexpr char aeiou[] = "aeiou";

    inline int aeiouIndex(char c) {
        for (int i = 0; i < 5; i++) {
            if (aeiou[i] == c) {
                return i;
            }
        }
        return -1;
    }
public:
    ll countOfSubstrings(string word, int k) {
        int cnt1_k = 0, cnt2_k = 0, left_k = 0;
        int bin_k[5] = {0};
        int cnt1_k1 = 0, cnt2_k1 = 0, left_k1 = 0;
        int bin_k1[5] = {0};
        ll ans = 0;
        for (char c : word) {
            int index = aeiouIndex(c);
            if (index == -1) {
                cnt2_k++;
                cnt2_k1++;
            } else {
                bin_k[index]++;
                if (bin_k[index] == 1) {
                    cnt1_k++;
                }
                bin_k1[index]++;
                if (bin_k1[index] == 1) {
                    cnt1_k1++;
                }
            }

            while (cnt1_k == 5 && cnt2_k >= k) {
                index = aeiouIndex(word[left_k++]);
                if (index == -1) {
                    cnt2_k--;
                } else {
                    bin_k[index]--;
                    if (!bin_k[index]) {
                        cnt1_k--;
                    }
                }
            }
            while (cnt1_k1 == 5 && cnt2_k1 > k) {
                index = aeiouIndex(word[left_k1++]);
                if (index == -1) {
                    cnt2_k1--;
                } else {
                    bin_k1[index]--;
                    if (!bin_k1[index]) {
                        cnt1_k1--;
                    }
                }
            }
            ans += left_k - left_k1;
        }
        return ans;
    }
};