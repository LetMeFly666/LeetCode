#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        bool already[1000] = {false};
        int ans = 0;
        for (int i = 0, n = digits.size(); i < n; i++) {
            if (digits[i] == 0) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j || digits[k] % 2) {  // 别忘了只要偶数
                        continue;
                    }
                    int val = digits[i] * 100 + digits[j] * 10 + digits[k];
                    ans += !already[val];
                    already[val] = true;
                }
            }
        }
        return ans;
    }
};
