#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minAddToMakeValid(string& s) {
        int left = 0;
        int ans = 0;
        for (char& c : s) {
            if (c == '(') {
                left++;
            }
            else {
                if (left) {
                    left--;
                }
                else {
                    ans++;
                }
            }
        }
        return ans + left;
    }
};