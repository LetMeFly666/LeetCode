/*
 * @Author: LetMeFly
 * @Date: 2025-08-10 17:20:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-10 17:24:03
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    // unordered_set<unordered_map<int, int>> times;  // 无默认哈希函数
    static unordered_set<string> can;

    void initCan() {
        if (!can.empty()) {
            return;
        }
        for (int i = 0; i <= 30; i++) {
            string s = to_string(1 << i);
            sort(s.begin(), s.end());
            can.insert(s);
        }
    }
public:
    bool reorderedPowerOf2(int n) {
        initCan();
        string s = to_string(n);
        sort(s.begin(), s.end());
        return can.count(s);
    }
};