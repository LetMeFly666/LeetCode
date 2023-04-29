/*
 * @Author: LetMeFly
 * @Date: 2023-04-29 13:56:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-04-29 14:06:35
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    bool equalFrequency(string word) {
        int bin[26] = {0};
        for (char c : word) {
            bin[c - 'a']++;
        }
        sort(bin, bin + 26);
        int last = 0;
        bool hasBig = false;
        for (int i = 0; i < 26; i++) {
            if (bin[i]) {
                if (last) {
                    if (bin[i] != last) {
                        if (hasBig) {
                            return false;
                        }
                        hasBig = true;
                    }
                }
                else {
                    last = bin[i];
                }
            }
        }
        return hasBig || last == 1;  // last == 1是特判每个字母都出现了一次的情况。这样的话，删掉一个字母同样符合条件
    }
};
#else  // FirstTry
// SecondTry
class Solution {
private:
    bool isSame(int* a) {
        int val = 0;
        for (int i = 0; i < 26; i++) {
            if (a[i]) {
                if (val) {
                    if (a[i] != val) {
                        return false;
                    }
                }
                else {
                    val = a[i];
                }
            }
        }
        return true;
    }
public:
    bool equalFrequency(string word) {
        int bin[26] = {0};
        for (char c : word) {
            bin[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (bin[i]) {
                bin[i]--;
                if (isSame(bin)) {
                    return true;
                }
                bin[i]++;
            }
        }
        return false;
    }
};
#endif  // FirstTry