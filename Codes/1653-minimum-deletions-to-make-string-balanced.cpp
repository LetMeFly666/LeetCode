/*
 * @Author: LetMeFly
 * @Date: 2023-03-06 11:52:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-06 12:03:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 空间复杂度O(n)
class Solution {
public:
    int minimumDeletions(string& s) {
        vector<int> frontB(s.size() + 1, 0);
        vector<int> backA(s.size() + 1, 0);
        int ans = s.size() - 1;
        for (int i = 1; i <= s.size(); i++) {
            frontB[i] = frontB[i - 1] + (s[i - 1] == 'b');
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            backA[i] = backA[i + 1] + (s[i] == 'a');
        }
        for (int i = 0; i <= s.size(); i++) {
            ans = min(ans, backA[i] + frontB[i]);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int minimumDeletions(string& s) {
        int fontB = 0;
        int backA = count(s.begin(), s.end(), 'a');
        int ans = s.size() - 1;
        for (int i = 0; i <= s.size(); i++) {
            ans = min(ans, backA + fontB);
            if (i < s.size()) {
                if (s[i] == 'a') {
                    backA--;
                }
                else {
                    fontB++;
                }
            }
        }
        return ans;        
    }
};
#endif  // FirstTry